drop database if exists terrain_elevation_db;
create database terrain_elevation_db character set utf8 collate utf8_general_ci;

use terrain_elevation_db;

create table if not exists terrain_elevation_table(
	id int primary key auto_increment,
	x	float,
	y	float,
	zdata blob
)engine = InnoDB, default charset = utf8 collate utf8_general_ci;


-- 创建存储过程 --

drop procedure if exists setTerrainData(in float x, in float y, blob z);
delimiter *

create procedure setTerrainData(in float x, in float y, in blob z)
begin
	insert into terrain_elevation_table(x, y, zdata) values (x, y, z);
end *
delimiter;