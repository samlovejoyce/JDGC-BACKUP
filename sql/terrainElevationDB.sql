drop database if exists terrain_elevation_db;
create database terrain_elevation_db character set utf8 collate utf8_general_ci;

use terrain_elevation_db;

drop table if exists terrain_elevation_table;
create table if not exists terrain_elevation_table(
	id int primary key auto_increment,
	x	float,
	y	float,
	zdata blob
)engine = InnoDB, default charset = utf8 collate utf8_general_ci;


-- 创建存储过程 --
-- select count(*) from terrain_elevation_table where id>0;