INSERT INTO genre(id, genre) 
values
(1, 'Rock'),
(2, 'Pop'),
(3, 'House'),
(4, 'Folk'),
(5, 'Indi');

INSERT INTO executor(id, executor) 
values
(1, 'Bob Goroh'),
(2, 'Mobi'),
(3, 'Rob'),
(4, 'Marli'),
(5, 'Bint Anderson'),
(6, 'Karlson'),
(7, 'Bugoga'),
(8, 'Tapki Diryavie');

INSERT INTO genre_executor (genre_id, executor_id) 
values
(1, 1),
(3, 1),
(4, 2),
(2, 3),
(4, 3),
(5, 4),
(2, 5),
(1, 6),
(2, 7),
(5, 7),
(3, 8);

INSERT INTO album (album, year) 
values
('Air', 2008),
('Seven', 2018),
('Bad and Good', 2021),
('Enter', 2011),
('12.12.12', 2012),
('Months Ago', 2020),
('F5', 2018),
('Syntax Error', 2018);

INSERT INTO tracks (album_id, track, time_t) 
values
(1, 'Track1', cast('00:03:50' as time)),
(2, 'Track2', cast('00:02:30' as time)),
(3, 'Track3', cast('00:03:30' as time)),
(4, 'Track4', cast('00:03:43' as time)),
(5, 'Track5', cast('00:04:12' as time)),
(6, 'My Track6', cast('00:03:30' as time)),
(7, 'Track7', cast('00:02:31' as time)),
(8, 'Track8', cast('00:03:30' as time)),
(3, 'Track9', cast('00:03:34' as time)),
(5, 'Track10', cast('00:04:30' as time)),
(5, 'Track11 my', cast('00:03:21' as time)),
(1, 'Track12', cast('00:05:47' as time)),
(8, 'Track13', cast('00:03:24'  as time)),
(7, 'Track14', cast('00:03:30'  as time)),
(2, 'Track15', cast('00:30:30'  as time));

INSERT INTO compilation (name, year, track_id) 
values
('compilation1', 2008, 1),
('compilation1', 2008, 9),
('compilation2', 2018, 2),
('compilation2', 2018, 12),
('compilation3', 2021, 8),
('compilation3', 2021, 10),
('compilation4', 2011, 4),
('compilation5', 2012, 5),
('compilation5', 2012, 11),
('compilation6', 2020, 6),
('compilation6', 2020, 15),
('compilation7', 2022, 7),
('compilation7', 2022, 13),
('compilation8', 2018, 14),
('compilation8', 2018, 8);

INSERT INTO executor_and_album (album_id, executor_id) 
values
(1, 1),
(2, 1),
(3, 2),
(4, 3),
(5, 3),
(6, 4),
(7, 5),
(8, 6),
(2, 7),
(5, 7),
(3, 8);
