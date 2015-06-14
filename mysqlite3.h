/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*
*   文件名称：mysqlite3.h
*   创 建 者：Gavin (E-mail:gavinlu1015@gmail.com)
*   创建日期：2015年01月27日
*   描    述：
*
================================================================*/

#ifndef __MYSQLITE3__
#define __MYSQLITE3__

#include <sqlite3.h>
#include <stdio.h>

#define MYSQLITE3_DEBUD

#ifdef MYSQLITE3_DEBUD
#define mysql_debug(fmt,arg...) printf(fmt,##arg);
#else
#define mysql_debug(fmt,arg...)
#endif

/* open sqlite3 db */
sqlite3* mysqlite3_open(char *path);
/* close sqlite3 db */
void mysqlite3_close(sqlite3 *db);
/* release error msg memory */
void mysqlite3_free_errmsg(char *errmsg);
/* release data when you use mysqlite3_get_data */
void mysqlite3_free_result(char **result);
/* insert data */
int mysqlite3_insertdata(sqlite3 *db, char *sql);
/* delete data */
int mysqlite3_del_data(sqlite3 *db, char *sql);
/* update data */
int mysqlite3_update_data(sqlite3 *db, char *sql);
/* query data*/
int mysqlite3_get_data(sqlite3 *db, char *sql, char **result, int *row, int *col);



#endif

