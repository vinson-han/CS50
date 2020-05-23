SELECT avg(rating)
FROM
ratings
Join movies  on ratings.movie_id = movies.id
WHERE year = 2012