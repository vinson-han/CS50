Select DISTINCT people.name
from people
join stars on stars.person_id = people.id
WHERE movie_id and not (people.name ="Kevin Bacon" AND people.birth = 1958)
and

movie_id in 
(Select movies.id
From movies
Join stars on movies.id = stars.movie_id
join people on stars.person_id = people.id
Where people.name = "Kevin Bacon" and birth = 1958)
