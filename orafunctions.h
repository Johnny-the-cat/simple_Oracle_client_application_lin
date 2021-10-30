#pragma once

#include "oratypes.h"
#include "oci.h"
#include <stdbool.h>

//Функция получает указатели на функции OCI
bool LoadOciFunctions(void * ocilib);

//Функция инициализации хендлов OCI окружения и ошибок. 
bool InitOraEnvironment(OCIEnv **hOraEnv, OCIError **hOraErr);
//Функция освобождения хендлов OCI окружения и ошибок. 
void CloseOraEnvironment(OCIEnv *hOraEnv, OCIError *hOraErr);

//Функция вывода текста ошибки
void checkerr(OCIError *errhp, sword status);

//Функция создания сессии
bool CreateSession(OCIEnv *hOraEnv, OCIError *hOraErr, OCIServer **hOraServer, OCISvcCtx **hOraSvcCtx, OCISession **hOraSession, const char *username, const char *password, const char *dbname, int assysdba);
//Функция закрытия сессии
void CloseSession(OCIError *hOraErr, OCIServer *hOraServer, OCISvcCtx *hOraSvcCtx, OCISession *hOraSession);


//Функция для выполнения sql выражения. Не подходит для SELECT, использование для множественных INSERT-ов неоптимально.
bool ExecuteStatement(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr, const char *statement);

bool InsertDataInTable(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr);

bool SelectDataFromTable(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr);