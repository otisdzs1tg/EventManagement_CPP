const API_URL = "http://localhost:8080/api/events";

// 1. Hàm lấy và hiển thị danh sách sự kiện từ Backend
async function fetchEvents() {
    try {
        const response = await fetch(API_URL);
        const result = await response.json();

        const list = document.getElementById("event-list");
        list.innerHTML = ""; // Xóa danh sách cũ đi để cập nhật cái mới

        // Lấy từng sự kiện trong mảng data và tạo thẻ <li> để in ra màn hình
        result.data.forEach(event => {
            const li = document.createElement("li");
            li.textContent = `${event.title} - ${event.location}`;
            list.appendChild(li);
        });
    } catch (error) {
        console.error("Lỗi fetch API:", error);
    }
}

// 2. Hàm gửi sự kiện mới lên C++ Backend
async function addEvent() {
    // Lấy nội dung người dùng nhập vào 2 ô text
    const title = document.getElementById("title").value;
    const location = document.getElementById("location").value;

    // Đóng gói thành một object
    const newEvent = { title, location };

    // Gửi yêu cầu (Request) dạng POST mang theo dữ liệu lên Backend
    await fetch(API_URL, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(newEvent)
    });

    alert("Đã thêm sự kiện!");
    fetchEvents(); // Tải lại danh sách để hiện ngay sự kiện vừa thêm
}

// 3. Tự động chạy hàm lấy danh sách ngay khi vừa mở trang web
fetchEvents();