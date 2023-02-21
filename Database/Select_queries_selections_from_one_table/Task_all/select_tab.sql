SELECT album, "year"  FROM album
WHERE "year" = 2018;

SELECT track, time_t FROM tracks
where time_t = (select MAX(time_t) from tracks);

SELECT track FROM tracks
WHERE time_t > '00:03:30';

SELECT "name" FROM compilation c 
WHERE "year"  BETWEEN 2018 AND 2020;

select executor from executor
where (char_length(executor)-char_length(replace(executor,' ',''))+1)=1;

SELECT track FROM tracks
WHERE track ILIKE '%my%';