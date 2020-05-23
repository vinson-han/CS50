CREATE INDEX  person_index on stars(person_id); 
Create INDEX movie_index on stars(movie_id);
Create Index movivename_index on movies(title);

Select people.name
FROM
people
Join stars on stars.person_id = people.id
Join movies on movies.id = stars.movie_id
WHERE movies.title = "Toy Story"