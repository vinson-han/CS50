SELECT DISTINCT(people.name)
from ratings
Join movies on movies.id = ratings.movie_id
Join directors on directors.movie_id = ratings.movie_id
Join people on people.id = directors.person_id
Where rating >= 9.0