/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: trash
 *
 * Created on October 30, 2021, 10:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <string.h>
#include "orafunctions.h"

//Функция для парсинга строки запуска приложения, извлекаем, логин, пароль и строку коннекта к базе
bool parseCmdLine(int argc, char* argv[], char *login, char *pass, char *dblink);

int main(int argc, char* argv[])
{
	//Логин для подключения. Получаем из аргументов командной строки. 
	char login[32] = { 0 };
	//Пароль для подключения. Получаем из аргументов командной строки. 
	char pass[32] = { 0 };
	//Строка подключения к базе данных.
	char dbconnect[128] = { 0 };
	
	//Получаем необходимые данные из аргументов командной строки
	parseCmdLine(argc, argv, login, pass, dbconnect);


	//Указатель на подключаемую библиотеку OCI. По завершении работы нужно освободить, вызвав dlclose(ocimodule);
	void *ocimodule = NULL;
	//Структура окружения (Oracle Environment) Инициализируется функцией InitOraEnvironment. Особождается функцией CloseOraEnvironment
	OCIEnv *hOraEnv = NULL;
	//Структура для получения и вывода ошибок работы функций OCI.dll.Инициализируется функцией InitOraEnvironment. Особождается функцией CloseOraEnvironment
	OCIError *hOraErr = NULL;


	//СТруктура OCIServer для создания сессии. Сессия закрывается вызовом функции CloseSession
	OCIServer *hOraServer = NULL;
	//СТруктура OCISvcCtx для создания сессии. Сессия закрывается вызовом функции CloseSession
	OCISvcCtx *hOraSvcCtx = NULL;
	//СТруктура OCISession для создания сессии. Сессия закрывается вызовом функции CloseSession
	OCISession *hOraSession = NULL;

	printf("Подключаем библиотеку oci.dll\n");
	
        ocimodule = dlopen("libclntsh.so", RTLD_LAZY);
        if (!ocimodule) 
        {
            fprintf(stderr, "Couldn't open libclntsh.so: %s\n", dlerror());
            printf("Убедитесь, что Oracle Client необходимой разрядности установлен и добавлен в переменную окружения LD_LIBRARY_PATH\n");
            exit(EXIT_FAILURE);
        }

	printf("Загружаем oci функции\n");
	if (!LoadOciFunctions(ocimodule))
	{
		printf("Не удалось загрузить все необходимые OCI функции. Проверьте версию oci\n");
		dlclose(ocimodule);
		exit(EXIT_FAILURE);
	}

	printf("Инициализируем окружение\n");
	if (!InitOraEnvironment(&hOraEnv, &hOraErr))
	{
		printf("Не получается инициализировать OCI окружение, приложение будет закрыто\n");
		dlclose(ocimodule);
		return EXIT_FAILURE;
	}

	//копия логина, которая будет приведена в верхнему регистру. Сревнением с "SYS" определяется, нужен ли флаг OCI_SYSDBA
	char tmpLogin[32] = { 0 };
	strcpy(tmpLogin, login);
        int i;
        for (i = 0; tmpLogin[i] != 0; i++)
        {
            tmpLogin[i] = toupper(tmpLogin[i]);
        }

	printf("Подключаемся к базе\n");
	if (!CreateSession(hOraEnv, hOraErr, &hOraServer, &hOraSvcCtx, &hOraSession, login, pass, dbconnect, !strcmp("SYS", tmpLogin)))
	{
		printf("Не получается подключиться к базе. Освобождаем ресурсы и завершаем работу приложения\n");

		CloseOraEnvironment(hOraEnv, hOraErr);
		dlclose(ocimodule);

		return EXIT_FAILURE;
	}

	char *create_table_statement = "CREATE TABLE simple_table (id NUMBER, textfield VARCHAR(100)) ";
	printf("Создаем тестовую таблицу\n");
	ExecuteStatement(hOraSvcCtx, hOraEnv, hOraErr, create_table_statement);

	printf("Вставляем данные в таблицу\n");
	InsertDataInTable(hOraSvcCtx, hOraEnv, hOraErr);

	printf("Получаем данные из таблицы\n");
	SelectDataFromTable(hOraSvcCtx, hOraEnv, hOraErr);

	printf("Удаляем за собой таблицу\n");
	ExecuteStatement(hOraSvcCtx, hOraEnv, hOraErr, "drop table simple_table");

	printf("Отключаемся и завершаем работу приложения\n");
	CloseSession(hOraErr, hOraServer, hOraSvcCtx, hOraSession);
	CloseOraEnvironment(hOraEnv, hOraErr);
	dlclose(ocimodule);
	return EXIT_FAILURE;

}