SELECT DISTINCT name
from people
JOIN stars on stars.person_id = people.id
Join movies on movies.id = stars.movie_id
WHERE movies.year = 2004
ORDER By birth