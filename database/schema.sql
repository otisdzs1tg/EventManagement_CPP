CREATE DATABASE EventDB;
USE EventDB;

CREATE TABLE events (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    event_date DATE NOT NULL,
    location VARCHAR(255) NOT NULL,
    description TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Thêm một sự kiện mẫu để test
INSERT INTO events (title, event_date, location, description) 
VALUES ('Hội thảo AI 2026', '2026-05-20', 'TP. Hồ Chí Minh', 'Hội thảo về tương lai của AI trong lập trình.');