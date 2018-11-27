-- 创建数据库--
drop database if exists terrain_elevation_db;
create database terrain_elevation_db character set utf8 collate utf8_general_ci;

use terrain_elevation_db;

-- 创建存储表 --
drop table if exists terrain_elevation_table;
create table if not exists terrain_elevation_table(
	id int primary key auto_increment,
	x	float,
	y	float,
	zdata blob
)engine = InnoDB, default charset = utf8 collate utf8_general_ci;

-- 创建索引 --
create index x_index using btree on terrain_elevation_table (x);

-- 创建存储过程 --
-- select count(*) from terrain_elevation_table where id>0;