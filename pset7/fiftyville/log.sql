-- Keep a log of any SQL queries you execute as you solve the mystery.

--  ocorreu em 28 de julho de 2020 na Chamberlin Street.

SELECT description FROM crime_scene_reports
WHERE year = 2020
AND month = 7
AND day = 28
AND street = 'Chamberlin Street';

-- o roubo teve 3 testemunhas
SELECT name, transcript FROM interviews
WHERE year = 2020 AND month = 7 AND day = 28 AND transcript LIKE '%courthouse%';

-- dados das testumunhas
SELECT  * FROM people
WHERE name IN ('Ruth', 'Eugene', 'Raymond');

-- eugene é o unico que tem passaporte (suspeito)



























-- | 295 | 2020 | 7 | 28 | Rua Chamberlin | O roubo do pato CS50 ocorreu às 10h15 no tribunal da Chamberlin Street
-- As entrevistas foram realizadas hoje com três testemunhas que estavam presentes no momento –
-- cada uma das transcrições das entrevistas menciona o tribunal.

