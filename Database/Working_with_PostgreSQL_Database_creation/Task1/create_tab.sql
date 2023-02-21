create table if not exists genre(
id serial primary key,
genre varchar(120) not null
);

create table if not exists executor(
id serial primary key,
executor varchar(120) not null
);

create table if not exists album(
id serial primary key,
album varchar(120) not null,
year integer not null
);

create table if not exists tracks(
id serial primary key,
album_id integer not null references album(id),
track varchar(120) not null,
time_t varchar not null
);

--Сборник имеет название и год выпуска. 
--В него входят различные треки из разных альбомов

create table if not exists compilation(
id serial primary key,
name varchar(120) not null,
year integer not null,
track_id integer not null references tracks(id)
);

--Ранее было ограничение, что каждый исполнитель поет строго в одном жанре - пора убрать это ограничение. 
--Исполнители могут петь в разных жанрах, как и одному жанру могут принадлежать несколько исполнителей.

create table if not exists genre_executor(
id serial primary key,
executor_id integer not null references executor(id),
genre_id integer not null references genre(id)

);

--Аналогичное ограничение было и с альбомами у исполнителей (альбом мог выпустить только один исполнитель). 
--Теперь альбом могут выпустить несколько исполнителей вместе. 
--Как и исполнитель может принимать участие во множестве альбомов.

create table if not exists executor_and_album(
id serial primary key,
album_id integer not null references album(id),
executor_id integer not null references executor(id)
);

