SELECT title,rating
FROM
movies
Join stars on stars.movie_id = movies.id
Join people on people.id = stars.person_id
JOIN ratings on ratings.movie_id = stars.movie_id
Where people.name = "Chadwick Boseman"
Order By rating DESC
Limit 5
