SELECT title
FROM movies
Where movies.id in (

Select movie_id
from
people
Join stars on stars.person_id = people.id
Where name = "Johnny Depp"
INTERSECT
Select movie_id
from
people
Join stars on stars.person_id = people.id
Where name = "Helena Bonham Carter")

