-- 1. Tạo cơ sở dữ liệu
CREATE DATABASE EventDB;
USE EventDB;

-- 2. Tạo bảng lưu trữ thông tin sự kiện
CREATE TABLE events (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    event_date DATE NOT NULL,
    location VARCHAR(255) NOT NULL,
    description TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- 3. Thêm dữ liệu mẫu để kiểm tra
INSERT INTO events (title, event_date, location, description)
VALUES ('Hội thảo AI 2026', '2026-05-20', 'TP. Hồ Chí Minh', 'Hội thảo về tương lai của trí tuệ nhân tạo.');