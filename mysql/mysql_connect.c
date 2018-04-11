#include<my_global.h>
//#include<my_sys.h>
#include<mysql.h>

char *opt_host_name = NULL;
char *opt_username =NULL;
char *opt_password = NULL;
char *opt_db_name = NULL;
unsigned int opt_port_num = 0;
char *opt_socket_name = NULL;
unsigned int opt_flags = 0;

void process_result_Set(MYSQL *conn, MYSQL_RES *res_set);
void print_bashes(MYSQL_RES *res_set);

static void print_error(MYSQL *conn, char *message)
{
	fprintf(stderr, "%s\n", message);
	if(conn != NULL)
	{
		fprintf(stderr, "Error %u (%s): %s\n", mysql_errno(conn), mysql_sqlstate(conn), mysql_error(conn));
	}
}

int main(int argc, char *argv[])
{
//	MY_INIT(argv[0]);
	MYSQL *conn;
	
#if 0
	if(mysql_libary_init(0, NULL, NULL))
	{
		printf("mysql_libary_init() faild\n");
		return -1;
	}	
#endif

	conn = mysql_init(NULL);
	if(NULL == conn)
	{
		//printf("mysql_init() faild\n");
		print_error(NULL, "mysql_init() failed...");
		return -1;
	}
	if(mysql_real_connect(conn, opt_host_name, opt_username, opt_password, "test", opt_port_num, opt_socket_name, opt_flags) == NULL)
	{
		//printf("mysql_real_connect() faild\n");
		print_error(conn, "mysql_real_connect() failed...");
		mysql_close(conn);
		return -1;
	}
	
	if(mysql_query(conn, "insert into test set name = 'baihl'") != 0)
	{
		print_error(conn, "insert into test failed...");
	}
	else
	{
		printf("insert into test is successed; affected rows : %lu\n", mysql_affected_rows(conn));
	}
	
	MYSQL_RES *res_set;
	
	if(mysql_query(conn, "select * from test") != 0)
	{
		print_error(conn, "insert into test failed...");
	}
	else
	{
		res_set = mysql_store_result(conn);
		if(res_set == NULL)
		{
			print_error(conn, "mysql_store_result() failed...");
		}
		else
		{
			process_result_Set(conn, res_set);
			mysql_free_result(res_set);
		}
		//printf("insert into test is successed; affected rows : %lu\n", mysql_affected_rows(conn));
	}
	
	mysql_close(conn);
//	mysql_libary_end();

	return 0;
}

#if 0
void process_result_Set(MYSQL *conn, MYSQL_RES *res_set)
{
	MYSQL_ROW row;
	unsigned int i;
	while((row = mysql_fetch_row(res_set)) != NULL)
	{
		for(i = 0; i < mysql_num_fields(res_set); i++)
		{
			if(i > 0)
			{
				fputc('\t', stdout);
			}
			printf("%s", row[i] != NULL ? row[i] : "NULL" );
		}
		fputc('\n', stdout);
	}
	if(mysql_errno(conn) != 0)
	{
		print_error(conn, "mysql_fetch_row() failed\n");
	}
	else
	{
		printf("Number of rows returned: %lu\n", mysql_num_rows(res_set));
	}
}
#endif

void print_bashes(MYSQL_RES *res_set)
{
	MYSQL_FIELD *field;
	unsigned int i, j;
	
	mysql_field_seek(res_set, 0);
	fputc('+', stdout);
	for(i = 0; i < mysql_num_fields(res_set); i++)
	{
		field = mysql_fetch_field(res_set);
		for(j = 0; j < field->max_length + 2; j++)
		{
			fputc('-', stdout);
		}
		fputc('+', stdout);
	}
	fputc('\n', stdout);
}

void process_result_Set(MYSQL *conn, MYSQL_RES *res_set)
{
	MYSQL_ROW row;
	MYSQL_FIELD *field;
	unsigned long col_len;
	unsigned int i;
	
	mysql_field_seek(res_set, 0);
	for(i = 0; i < mysql_num_fields(res_set); i++)
	{
		field = mysql_fetch_field(res_set);
		col_len = strlen(field->name);
		if(col_len < field->max_length)
		{
			col_len = field->max_length;
		}
		if(col_len < 4 && !IS_NOT_NULL(field->flags))
			col_len = 4;
		field->max_length = col_len;
	}
	print_bashes(res_set);
	fputc('|', stdout);
	mysql_field_seek(res_set, 0);
	for(i = 0; i < mysql_num_fields(res_set); i++)
	{
		field = mysql_fetch_field(res_set);
		printf(" %-*s |", (int)field->max_length, field->name);
	}
	fputc('\n', stdout);
	print_bashes(res_set);
	
	while((row = mysql_fetch_row(res_set)) != NULL)
	{
		mysql_field_seek(res_set, 0);
		fputc('|', stdout);
		for(i = 0; i < mysql_num_fields(res_set); i++)
		{
			field = mysql_fetch_field(res_set);
			if(row[i] == NULL)
				printf(" %-*s |", (int)field->max_length, "NULL");
			else if(IS_NUM(field->type))
				printf(" %*s |", (int)field->max_length, row[i]);
			else
				printf(" %-*s |", (int)field->max_length, row[i]);
		}
		fputc('\n', stdout);
	}
	print_bashes(res_set);
	printf("Number of rows returned: %lu\n", (unsigned long)mysql_num_rows(res_set));
}



















