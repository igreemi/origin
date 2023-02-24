-- Количество исполнителей в каждом жанре;

select genre, count(executor_id) executor_q from genre g
join genre_executor ge on g.id = ge.genre_id
group by g.genre
order by executor_q desc;

-- Количество треков, вошедших в альбомы 2019-2020 годов;

select count(track) track_q from tracks t
join album a on t.album_id = a.id
where a."year" > 2018 and a."year" < 2021
order by track_q desc;

-- Средняя продолжительность треков по каждому альбому;

select album ,avg(time_t) time_q from tracks t
join album a on t.album_id = a.id
group  by album;

-- Все исполнители, которые не выпустили альбомы в 2020 году;

select distinct executor Исполнители from executor e 
join executor_and_album eaa on e.id = eaa.executor_id
join album a on a.id = eaa.album_id 
where a."year" != 2020;

-- Названия сборников, в которых присутствует конкретный исполнитель (выберите сами);

select distinct name from compilation c 
join tracks t on c.track_id = t.id 
join album a on a.id = t.album_id 
join executor_and_album eaa on eaa.album_id = a.id 
join executor e on e.id = eaa.executor_id 
where e.executor = 'Rob';

-- Название альбомов, в которых присутствуют исполнители более 1 жанра;

select distinct album from album a 
join executor_and_album eaa on eaa.album_id = a.id
join executor e on e.id = eaa.executor_id
join genre_executor ge on ge.executor_id  = e.id 
join genre g on g.id = ge.genre_id 
where g.id > 1;

-- Наименование треков, которые не входят в сборники;

select track from tracks t
where t.id not in (select track_id from compilation);

-- Исполнителя(-ей), написавшего самый короткий по продолжительности трек (теоретически таких треков может быть несколько);

select distinct executor from executor e 
join executor_and_album eaa on e.id = eaa.executor_id 
join album a on eaa.album_id = a.id 
join tracks t on a.id = t.album_id 
where t.time_t  = (select min(time_t) from tracks) ;

-- Название альбомов, содержащих наименьшее количество треков.

select distinct album from album a
join tracks t on t.album_id = a.id
where t.album_id in (
select album_id from tracks
group by album_id
having count(id) = (
select count(id) from tracks
group by album_id
order by count
limit 1
)
)
order by a.album;
