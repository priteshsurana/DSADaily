SELECT b.book_id, a.title, a.author, a.genre, a.publication_year, borrowedCount as current_borrowers
FROM library_books as a
RIGHT JOIN
(SELECT book_id, COUNT(book_id) as borrowedCount
FROM borrowing_records
WHERE return_date IS NULL
GROUP BY book_id) as b
ON a.book_id=b.book_id
WHERE a.total_copies=b.borrowedCount
ORDER BY b.borrowedCount DESC, a.title ASC