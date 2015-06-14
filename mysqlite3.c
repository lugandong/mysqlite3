/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*
*   文件名称：mysqlite3.c
*   创 建 者：Gavin (E-mail:gavinlu1015@gmail.com)
*   创建日期：2015年01月27日
*   描    述：
*
================================================================*/
#include "mysqlite3.h"
#include <sqlite3.h>

/*
 *  Function: open sqlite3 db depend on path
 *  Remark:
 */
sqlite3* mysqlite3_open(char *path)
{
	sqlite3 *db;

	if (sqlite3_open(path, &db) != SQLITE_OK){
		mysql_debug("__%s__:%s\n", __func__, sqlite3_errmsg(db));
		return NULL;
	}

	return db;
}

/*
 *  Function:close sqlite3 db
 *  Remark:
 */
void mysqlite3_close(sqlite3 *db)
{
	sqlite3_close(db);
}

/*
 *  Function: release malloc memoery,
 *  when error hava
 *  Remark:
 */
void mysqlite3_free_errmsg(char *errmsg)
{
	sqlite3_free(errmsg);
}

/*
 *  Function: release malloc memoery,
 *  when you use mysqlite3_get_data
 *  Remark:
 */
void mysqlite3_free_result(char **result)
{
	sqlite3_free_table(result);
}

/*
 *  Function:insert data
 *  Remark:
 */
int mysqlite3_insertdata(sqlite3 *db, char *sql)
{
	char *errmsg;

	if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK){
		mysql_debug("__%s__:%s\n", __func__, errmsg);
		mysqlite3_free_errmsg(errmsg);

		return -1;
	}
	return 0;
}

/*
 *  Function: delete data
 *  Remark:
 */
int mysqlite3_del_data(sqlite3 *db, char *sql)
{
	char *errmsg;

	if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK){
		mysql_debug("__%s__:%s\n", __func__, errmsg);
		mysqlite3_free_errmsg(errmsg);

		return -1;
	}
	return 0;
}

/*
 *  Function:update sqlite3 data
 *  Remark:
 */
int mysqlite3_update_data(sqlite3 *db, char *sql)
{
	char *errmsg;

	if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK){
		mysql_debug("__%s__:%s\n", __func__, errmsg);
		mysqlite3_free_errmsg(errmsg);

		return -1;
	}
	return 0;
}

/*
 *  Function:get sqlite3 data depend on details
 *  Remark:
 */
int mysqlite3_get_data(sqlite3 *db, char *sql, char **result, int *row, int *col)
{
	char *errmsg;

	if(sqlite3_get_table(db, sql, &result, row, col, &errmsg) != SQLITE_OK){
		mysql_debug("__%s__:%s\n", __func__, errmsg);
		mysqlite3_free_errmsg(errmsg);
		return -1;
	}

	return 0;
}
