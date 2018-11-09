drop database if exists terrain_library;
create database terrain_library character set utf8 collate utf8_general_ci;

use terrain_library;

create table if not exists terrain_mesh(
	id int primary key auto_increment,
	tableName varchar(50),
	x	float,
	ystart	float,
	yend	float,
	delta float
)engine = InnoDB, default charset = utf8 collate utf8_general_ci;

create table if not exists height_table(
	t_id int not null,
	h_id int primary key auto_increment,
	z float
)engine = InnoDB, default charset = utf8 collate utf8_general_ci;


-- 为height_table关联外键 --
alter table height_table add constraint fk_id foreign key height_table(t_id) references terrain_mesh(id);

--  创建索引--
create index terrain_mesh_x_index on terrain_mesh(x asc);
create index terrain_mesh_name_index on terrain_mesh(tableName);
-- create index terrain_mesh_x_index on height_table(t_id asc); --


-- 创建存储过程 --

drop procedure if exists store_height_value;
delimiter *

create procedure store_height_value(int fk, float zvalue)
begin
	insert into height_table(t_id, z) value (fk, zvalue);
end *
delimiter;


/*drop PROCEDURE if exists constructTerrainData;
delimiter *

create PROCEDURE constructTerrainData (in width float, in height float, in resolution float)
begin
	declare i float default 0.0;
	declare j float default 0.0;
	while i < width do	
		while j < height do
			insert into terrain_mesh(x, y, z) values (i, j, 0.0);
			set j = j + resolution;
		end while;
		set i = i + resolution;
	end while;
end *
delimiter;
*/


-- 插入数据 --
insert into terrain_mesh(tableName, x, ystart, yend, delta) values
('试车场跑道', '0', '0.000', '245.880', '0.005'),
('试车场跑道', '0', '500.000', '1000.000', '0.005');

insert into height_table(t_id, z) values 
('1', '0.0'),
('1', '0.1'),
('1', '0.2'),
('1', '0.3'),
('2', '0.1'),
('2', '0.4');