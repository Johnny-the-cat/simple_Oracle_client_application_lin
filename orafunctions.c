
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "oci.h"
#include "oratypes.h"
#include "orl.h"
#include "ocipfndfn.h"
#include "orafunctions.h"
#include <stdbool.h>

#define CONSOLE_ERROR_OUTPUT

pOCIEnvCreate OCIEnvCreate;

pOCIEnvNlsCreate OCIEnvNlsCreate;

pOCITerminate OCITerminate;

pOCIHandleAlloc OCIHandleAlloc;

pOCIServerAttach OCIServerAttach;

pOCIAttrSet OCIAttrSet;

pOCISessionBegin OCISessionBegin;

pOCISessionEnd OCISessionEnd;

pOCIStmtPrepare OCIStmtPrepare;

pOCIDefineByPos OCIDefineByPos;

pOCIStmtExecute OCIStmtExecute;

pOCIBindByName OCIBindByName;

pOCIBindByPos OCIBindByPos;

pOCITransCommit OCITransCommit;

pOCIHandleFree OCIHandleFree;

pOCIServerDetach OCIServerDetach;

pOCIStmtFetch2 OCIStmtFetch2;

pOCIErrorGet OCIErrorGet;

pOCIRawAllocSize OCIRawAllocSize;

pOCIRawAssignBytes OCIRawAssignBytes;

pOCILobFileSetName OCILobFileSetName;

pOCIDescriptorAlloc OCIDescriptorAlloc;

pOCIDescriptorFree OCIDescriptorFree;

pOCILobFileOpen OCILobFileOpen;

pOCILobFileClose OCILobFileClose;

pOCILobGetLength2 OCILobGetLength2;

pOCILobRead2 OCILobRead2;

pOCILobFileExists OCILobFileExists;



/*Функция получает адреса нужных процедур и функций из oci.dll*/
bool LoadOciFunctions(void * ocilib)
{
    const char *error;    
    
    dlerror(); 
    OCIEnvCreate = (pOCIEnvCreate)dlsym(ocilib,"OCIEnvCreate");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIEnvCreate: %s\n", error);
        return FALSE;
    }

    dlerror();
    OCIEnvNlsCreate = (pOCIEnvNlsCreate)dlsym(ocilib,"OCIEnvNlsCreate");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIEnvNlsCreate: %s\n", error);
        return FALSE;
    }
    
    dlerror();
    OCITerminate = (pOCITerminate)dlsym(ocilib,"OCITerminate");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCITerminate: %s\n", error);
        return FALSE;
    }

    dlerror();
    OCIHandleAlloc = (pOCIHandleAlloc)dlsym(ocilib,"OCIHandleAlloc");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIHandleAlloc: %s\n", error);
        return FALSE;
    }

    dlerror();
    OCIServerAttach = (pOCIServerAttach)dlsym(ocilib,"OCIServerAttach");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIServerAttach: %s\n", error);
        return FALSE;
    }
    
    dlerror();
    OCIAttrSet = (pOCIAttrSet)dlsym(ocilib,"OCIAttrSet");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIAttrSet: %s\n", error);
        return FALSE;
    }
    
    dlerror();
    OCISessionBegin = (pOCISessionBegin)dlsym(ocilib,"OCISessionBegin");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCISessionBegin: %s\n", error);
        return FALSE;
    }
    
    dlerror();
    OCISessionEnd = (pOCISessionEnd)dlsym(ocilib,"OCISessionEnd");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCISessionEnd: %s\n", error);
        return FALSE;
    }

    dlerror();
    OCIStmtPrepare = (pOCIStmtPrepare)dlsym(ocilib,"OCIStmtPrepare");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIStmtPrepare: %s\n", error);
        return FALSE;
    }
	
    dlerror();
    OCIDefineByPos = (pOCIDefineByPos)dlsym(ocilib,"OCIDefineByPos");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIDefineByPos: %s\n", error);
        return FALSE;
    }
	
    dlerror();
    OCIStmtExecute = (pOCIStmtExecute)dlsym(ocilib,"OCIStmtExecute");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIStmtExecute: %s\n", error);
        return FALSE;
    }
	
    dlerror();
    OCIBindByName = (pOCIBindByName)dlsym(ocilib,"OCIBindByName");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIBindByName: %s\n", error);
        return FALSE;
    }
	
    dlerror();
    OCIBindByPos = (pOCIBindByPos)dlsym(ocilib,"OCIBindByPos");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIBindByPos: %s\n", error);
        return FALSE;
    }
	
    dlerror();
    OCITransCommit = (pOCITransCommit)dlsym(ocilib,"OCITransCommit");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCITransCommit: %s\n", error);
        return FALSE;
    }

    dlerror();
    OCIHandleFree = (pOCIHandleFree)dlsym(ocilib,"OCIHandleFree");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIHandleFree: %s\n", error);
        return FALSE;
    }
	
    dlerror();
    OCIServerDetach = (pOCIServerDetach)dlsym(ocilib,"OCIServerDetach");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIServerDetach: %s\n", error);
        return FALSE;
    }
    
    dlerror();
    OCIStmtFetch2 = (pOCIStmtFetch2)dlsym(ocilib,"OCIStmtFetch2");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIStmtFetch2: %s\n", error);
        return FALSE;
    }
	
    dlerror();
    OCIErrorGet = (pOCIErrorGet)dlsym(ocilib,"OCIErrorGet");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIErrorGet: %s\n", error);
        return FALSE;
    }
	
    dlerror();
    OCIRawAllocSize = (pOCIRawAllocSize)dlsym(ocilib,"OCIRawAllocSize");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIRawAllocSize: %s\n", error);
        return FALSE;
    }
	
    dlerror();
    OCIRawAssignBytes = (pOCIRawAssignBytes)dlsym(ocilib,"OCIRawAssignBytes");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIRawAssignBytes: %s\n", error);
        return FALSE;
    }
    
    dlerror();
    OCILobFileSetName = (pOCILobFileSetName)dlsym(ocilib,"OCILobFileSetName");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCILobFileSetName: %s\n", error);
        return FALSE;
    }
	
    dlerror();
    OCIDescriptorAlloc = (pOCIDescriptorAlloc)dlsym(ocilib,"OCIDescriptorAlloc");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIDescriptorAlloc: %s\n", error);
        return FALSE;
    }
	
    dlerror();
    OCIDescriptorFree = (pOCIDescriptorFree)dlsym(ocilib,"OCIDescriptorFree");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCIDescriptorFree: %s\n", error);
        return FALSE;
    }
    
    dlerror();
    OCILobFileOpen = (pOCILobFileOpen)dlsym(ocilib,"OCILobFileOpen");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCILobFileOpen: %s\n", error);
        return FALSE;
    }

    dlerror();
    OCILobFileClose = (pOCILobFileClose)dlsym(ocilib,"OCILobFileClose");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCILobFileClose: %s\n", error);
        return FALSE;
    }
	
    dlerror();
    OCILobGetLength2 = (pOCILobGetLength2)dlsym(ocilib,"OCILobGetLength2");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCILobGetLength2: %s\n", error);
        return FALSE;
    }
	
    dlerror();
    OCILobRead2 = (pOCILobRead2)dlsym(ocilib,"OCILobRead2");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCILobRead2: %s\n", error);
        return FALSE;
    }

    dlerror();
    OCILobFileExists = (pOCILobFileExists)dlsym(ocilib,"OCILobFileExists");
    if ((error = dlerror())) 
    {
        printf("LoadOciFunctions: can't load OCILobFileExists: %s\n", error);
        return FALSE;
    }

	
    return TRUE;
}

void checkerr(OCIError *errhp, sword status)
{
	text errbuf[512];
	sb4 errcode = 0;

	switch (status)
	{
	case OCI_SUCCESS:
		//(void)printf("OCI_SUCCESS\n");
		break;
	case OCI_SUCCESS_WITH_INFO:
		(void)printf("Error - OCI_SUCCESS_WITH_INFO\n");
		break;
	case OCI_NEED_DATA:
		(void)printf("Error - OCI_NEED_DATA\n");
		break;
	case OCI_NO_DATA:
		(void)printf("Error - OCI_NODATA\n");
		break;
	case OCI_ERROR:
		(void)OCIErrorGet((dvoid *)errhp, (ub4)1, (text *)NULL, &errcode,
			errbuf, (ub4) sizeof(errbuf), OCI_HTYPE_ERROR);
		(void)printf("Error - %.*s\n", 512, errbuf);
		break;
	case OCI_INVALID_HANDLE:
		(void)printf("Error - OCI_INVALID_HANDLE\n");
		break;
	case OCI_STILL_EXECUTING:
		(void)printf("Error - OCI_STILL_EXECUTE\n");
		break;
	case OCI_CONTINUE:
		(void)printf("Error - OCI_CONTINUE\n");
		break;
	default:
		break;
	}
}


/*Функция инициализирует окружение OCIEnv и OCIError*/
bool InitOraEnvironment(OCIEnv **hOraEnv, OCIError **hOraErr)
{
	OCIEnv *localHandleOraEnv = NULL;
	OCIError *localHanleOraErr = NULL;
	
	
	if (OCIEnvCreate((OCIEnv **)&localHandleOraEnv,
		(ub4)OCI_DEFAULT | OCI_OBJECT,
		(const void  *)0,
		(const void  * (*)(void  *, size_t))0,
		(const void  * (*)(void  *, void  *, size_t))0,
		(const void(*)(void  *, void  *))0,
		(size_t)0, (void  **)0))

	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, InitOraEnvironment function - can not create OCI Environment handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, InitOraEnvironment function - can not create OCI Environment handle\n");
#endif
		return FALSE;
	}
	
	localHanleOraErr = NULL;
	if (OCIHandleAlloc((const void *)localHandleOraEnv,
		(void **)&localHanleOraErr,
		OCI_HTYPE_ERROR,
		(size_t)0,
		(void **)0))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, InitOraEnvironment function - can not allocate OCI Error handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, InitOraEnvironment function - can not allocate OCI Error handle\n");
#endif
		return FALSE;
	}
	
	*hOraEnv = localHandleOraEnv;
	*hOraErr = localHanleOraErr;

	return TRUE;

}

/*Процедура освобождает Error Handle и Environment Handle завершает сеанс работы с OCI*/
void CloseOraEnvironment(OCIEnv *hOraEnv, OCIError *hOraErr)
{
	if (OCIHandleFree(hOraErr, OCI_HTYPE_ERROR))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CloseOraEnvironment function - can not free OCI Error handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CloseOraEnvironment function - can not free OCI Error handle\n");
#endif
	}

	if (OCIHandleFree(hOraEnv, OCI_HTYPE_ENV))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CloseOraEnvironment function - can not free OCI Env handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CloseOraEnvironment function - can not free OCI Env handle\n");
#endif
	}

	OCITerminate(OCI_DEFAULT);
}


//Инициализируем OCISvcCtx, OCIServer, OCISession и подключаемся к серверу
bool CreateSession(OCIEnv *hOraEnv, OCIError *hOraErr, OCIServer **hOraServer, OCISvcCtx **hOraSvcCtx, OCISession **hOraSession, const char *usernameutf8, const char *passwordutf8, const char *dbnameutf8, int assysdba)
{
	OCIServer *localHandleOraServer;
	OCISvcCtx *localHandleOraSvcCtx;
	OCISession *localHandleSession;
	
	

	localHandleOraServer = NULL;
	if (OCIHandleAlloc((const void *)hOraEnv,
		(void **)&localHandleOraServer,
		OCI_HTYPE_SERVER,
		(size_t)0,
		(dvoid **)0))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CreateSession function - can not allocate server handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CreateSession function - can not allocate server handle\n");
#endif
		return FALSE;
	}
	
	if (OCIServerAttach(localHandleOraServer, hOraErr, (const OraText *)dbnameutf8, (sb4)strlen(dbnameutf8), (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Не могу подключиться к серверу БД. Проверьте TNS или строку подключения. Возможно, ошибка сети", L"Ошибка", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Unable to attach to server. Check TNS name or connect string. May be network error\n");
#endif
		return FALSE;
	}

	localHandleOraSvcCtx = NULL;
	if (OCIHandleAlloc((const void *)hOraEnv,
		(void **)&localHandleOraSvcCtx,
		OCI_HTYPE_SVCCTX,
		(size_t)0,
		(dvoid **)0))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CreateSession function - can not allocate service handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CreateSession function - can not allocate service handle\n");
#endif
		return FALSE;
	}
	
	if (OCIAttrSet((void *)localHandleOraSvcCtx, OCI_HTYPE_SVCCTX, (void *)localHandleOraServer, (ub4)0, OCI_ATTR_SERVER, (OCIError *)hOraErr) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CreateSession function - unable to put server handle to service context", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CreateSession function - unable to put server handle to service context for\n");
#endif
		return FALSE;
	}
	
        localHandleSession = NULL;
	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&localHandleSession, (ub4)OCI_HTYPE_SESSION, (size_t)0, (void **)0))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CreateSession function - can not allocate session handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CreateSession function - can not allocate session handle\n");
#endif
		return FALSE;
	}
	

	//Устанавливаем аттрибут "Имя пользователя"
	if (OCIAttrSet((void *)localHandleSession, (ub4)OCI_HTYPE_SESSION, (void *)usernameutf8, (ub4)strlen(usernameutf8), (ub4)OCI_ATTR_USERNAME, hOraErr) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CreateSession function - unable to set username to session handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CreateSession function - unable to set username to session handle\n");
#endif
		return FALSE;
	}

	//Устанавливаем аттрибут "Пароль"
	if (OCIAttrSet((void *)localHandleSession, (ub4)OCI_HTYPE_SESSION, (void *)passwordutf8, (ub4)strlen(passwordutf8), (ub4)OCI_ATTR_PASSWORD, hOraErr) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CreateSession function - unable to set password to session handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CreateSession function - unable to set password to session handle\n");
#endif
		return FALSE;
	}

	//Устанавливаем сессию
	if (OCISessionBegin(localHandleOraSvcCtx, hOraErr, localHandleSession, OCI_CRED_RDBMS, (ub4)(OCI_DEFAULT | (assysdba ? OCI_SYSDBA : 0))) != OCI_SUCCESS)
	//if (OCISessionBegin(localHandleOraSvcCtx, hOraErr, localHandleSession, OCI_CRED_RDBMS, (ub4)(OCI_DEFAULT | OCI_SYSDBA)) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Не получается установить рабочую сессию. Проверьте правильность пользователя и пароля", L"Ошибка", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Unable to begin session. Check your login and password is correct\n");
#endif
		return FALSE;
	}

	if (OCIAttrSet((void *)localHandleOraSvcCtx, (ub4)OCI_HTYPE_SVCCTX, (void *)localHandleSession, (ub4)0, (ub4)OCI_ATTR_SESSION, hOraErr) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CreateSession function - unable to set session handle into the service context handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CreateSession function - unable to set session handle into the service context handle.\n");
#endif
		return FALSE;
	}

	*hOraServer = localHandleOraServer;
	*hOraSvcCtx = localHandleOraSvcCtx;
	*hOraSession = localHandleSession;

	return TRUE;
}

//Отключаемся от сервера, и оосвобождаем хендлы OCISvcCtx, OCIServer, OCISession
void CloseSession(OCIError *hOraErr, OCIServer *hOraServer, OCISvcCtx *hOraSvcCtx, OCISession *hOraSession)
{
	if (OCISessionEnd(hOraSvcCtx, hOraErr, hOraSession, OCI_DEFAULT))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
	MessageBox(MainWindowHandle, L"Application error, CloseSession function - unable to end session", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
	printf("Application error, CloseSession function - unable to end session.\n");
#endif
	}

	if(OCIHandleFree(hOraSession, OCI_HTYPE_SESSION))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CloseSession function - unable to free session handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CloseSession function - unable to free session handle\n");
#endif
	}
	
	if(OCIHandleFree(hOraSvcCtx, OCI_HTYPE_SVCCTX))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CloseSession function - unable to free service context handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CloseSession function - unable to free service context handle\n");
#endif
	}
	
	if(OCIServerDetach(hOraServer, hOraErr, (ub4)OCI_DEFAULT))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CloseSession function - unable to detach server", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CloseSession function - unable to detach server\n");
#endif
	}
	
	if(OCIHandleFree(hOraServer, OCI_HTYPE_SERVER))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CloseSession function - unable to free server handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CloseSession function - unable to free server handle\n");
#endif
	}
}


bool ExecuteStatement(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr, const char *statement)
{
	sword status;
	

	OCIStmt *hOraPlsqlStatement = NULL;
	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&hOraPlsqlStatement, OCI_HTYPE_STMT, (size_t)0, (void **)0))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, ExecuteStatement function - can not allocate hOraPlsqlStatement handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, ExecuteStatement function - can not allocate hOraPlsqlStatement handle\n");
#endif
		return FALSE;
	}
	
	if (OCIStmtPrepare(hOraPlsqlStatement, hOraErr, (const OraText *)statement, (ub4)strlen(statement), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, ExecuteStatement function - unable to prepare statement", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, ExecuteStatement function - unable to prepare statement\n");
#endif
		OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);

		return FALSE;
	}

	status = OCIStmtExecute(hOraSvcCtx, hOraPlsqlStatement, hOraErr, (ub4)1, (ub4)0, (CONST OCISnapshot *) NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
	if (status != OCI_SUCCESS && status != OCI_SUCCESS_WITH_INFO)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, ExecuteStatement function - unable to execute plsql statement", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, ExecuteStatement function - unable to execute plsql statement\n");
#endif
		checkerr(hOraErr, status);
                OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
	return TRUE;
}


bool InsertDataInTable(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr)
{
	char * insert_statement = "INSERT INTO simple_table\
	(id, textfield)\
	VALUES\
	(:id, :string)";

	sword status;

	int id;
	char stringBuffer[100];

	OCIStmt *hOraPlsqlStatement = NULL;
	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&hOraPlsqlStatement, OCI_HTYPE_STMT, (size_t)0, (void **)0))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, InsertDataInTable function - can not allocate hOraPlsqlStatement handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, InsertDataInTable function - can not allocate hOraPlsqlStatement handle\n");
#endif
		return FALSE;
	}

	if (OCIStmtPrepare(hOraPlsqlStatement, hOraErr, (const OraText *)insert_statement, (ub4)strlen(insert_statement), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, InsertDataInTable function - unable to prepare statement", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, InsertDataInTable function - unable to prepare statement\n");
#endif
		OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIBind  *bnd1p = NULL;
	OCIBind  *bnd2p = NULL;
	OCIBindByName(hOraPlsqlStatement, &bnd1p, hOraErr, (text *)":id", -1, (void *)&id, (sb4)sizeof(id), SQLT_INT, (void *)0, (ub2 *)0, (ub2 *)0, (ub4)0, (ub4 *)0, OCI_DEFAULT);
	OCIBindByName(hOraPlsqlStatement, &bnd2p, hOraErr, (text *)":string", -1, (void *)stringBuffer, (sb4)(sizeof(stringBuffer)), SQLT_STR, (void *)0, (ub2 *)0, (ub2 *)0, (ub4)0, (ub4 *)0, OCI_DEFAULT);
	
	for (id = 1; id < 10; id++)
	{
		sprintf(stringBuffer, "This is the %d string", id);
		
		status = OCIStmtExecute(hOraSvcCtx, hOraPlsqlStatement, hOraErr, (ub4)1, (ub4)0, (CONST OCISnapshot *) NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
		if (status != OCI_SUCCESS && status != OCI_SUCCESS_WITH_INFO)
		{
			checkerr(hOraErr, status);
			OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
			return FALSE;
		}
	}


	OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);

	return TRUE;
}

bool SelectDataFromTable(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr)
{
	char * select_statement = "select id, textfield from simple_table order by id";

	sword status;

	int id;
	char stringBuffer[100];

	OCIStmt *hOraPlsqlStatement = NULL;
	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&hOraPlsqlStatement, OCI_HTYPE_STMT, (size_t)0, (void **)0))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, SelectDataFromTable function - can not allocate hOraPlsqlStatement handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, SelectDataFromTable function - can not allocate hOraPlsqlStatement handle\n");
#endif
		return FALSE;
	}

	if (OCIStmtPrepare(hOraPlsqlStatement, hOraErr, (const OraText *)select_statement, (ub4)strlen(select_statement), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, SelectDataFromTable function - unable to prepare statement", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, SelectDataFromTable function - unable to prepare statement\n");
#endif
		OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIDefine *OraIdDefine = NULL;
	if (OCIDefineByPos(hOraPlsqlStatement, &OraIdDefine, hOraErr, 1, (void *)&id, (sword)sizeof(id), SQLT_INT, (void *)0, (ub2 *)0, (ub2 *)0, OCI_DEFAULT) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, SelectDataFromTable function - unable to DefineByPos", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, SelectDataFromTable function - unable to DefineByPos\n");
#endif
		OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIDefine *OraStringDefine = NULL;
	if (OCIDefineByPos(hOraPlsqlStatement, &OraStringDefine, hOraErr, 2, (void *)stringBuffer, (sword)sizeof(stringBuffer), SQLT_STR, (void *)0, (ub2 *)0, (ub2 *)0, OCI_DEFAULT) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, SelectDataFromTable function - unable to DefineByPos OraUsernameDefine", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, SelectDataFromTable function - unable to DefineByPos OraUsernameDefine\n");
#endif
		OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	status = OCIStmtExecute(hOraSvcCtx, hOraPlsqlStatement, hOraErr, (ub4)0, (ub4)0, (CONST OCISnapshot *) NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
	if (status != OCI_SUCCESS && status != OCI_SUCCESS_WITH_INFO)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, SelectDataFromTable function - unable to execute plsql_user_to_list_statement", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, SelectDataFromTable function - unable to execute select sql statement\n");
#endif
		checkerr(hOraErr, status);
		OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	printf("id | textfield\n");
	while ((status = OCIStmtFetch2(hOraPlsqlStatement, hOraErr, 1, OCI_DEFAULT, 0, OCI_DEFAULT)) == OCI_SUCCESS || status == OCI_SUCCESS_WITH_INFO)
	{
		printf("%d | %s\n", id, stringBuffer);
	}

	OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
	return TRUE;

}
