SELECT title,rating
FROM
ratings
Join movies  on ratings.movie_id = movies.id
WHERE year = 2010 and rating is NOT NULL
Order By rating DESC, title ASC
SELECT title,rating
FROM
ratings
Join movies  on ratings.movie_id = movies.id
WHERE year = 2010 and rating is NOT NULL
Order By rating DESC, title ASC

