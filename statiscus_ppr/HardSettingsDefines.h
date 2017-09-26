#ifndef PIP_HARD_SETTINGS_DEFINES_H
#define PIP_HARD_SETTINGS_DEFINES_H

	#ifdef WIN32
	String _db_path = "./pip_statistic/";
	#else
	String _db_path = "/sdcard/pip_statistic/";
	#endif

	String _db_name = "db.s3db";

	String _db_create_sql =

"CREATE TABLE [controls] ( \
[name] VARCHAR(64)  UNIQUE NOT NULL, \
[controlid] INTEGER  PRIMARY KEY AUTOINCREMENT NOT NULL, \
[isused] INTEGER DEFAULT '1' NOT NULL \
); \
\
CREATE TABLE [vals] ( \
[control_id] INTEGER  NOT NULL, \
[val] FLOAT  NOT NULL, \
[timestamp] FLOAT  NOT NULL, \
[date_str] VARCHAR(15)  NOT NULL, \
[time_str] VARCHAR(15)  NOT NULL, \
[description] VARCHAR(128)  NULL \
);";

#endif
