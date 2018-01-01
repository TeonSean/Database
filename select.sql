CREATE DATABASE test;
USE test;
CREATE TABLE test (a INT, b INT);
CREATE INDEX test (a) DENSITY (3);
INSERT INTO test VALUES (1, 1), (2, 2), (3, 3), (4, 4), (9465, 5), (-156, 7), (-999, -89156), (654, 321);
SELECT * FROM test WHERE a <> 654 AND a <> b;
DROP DATABASE test;
