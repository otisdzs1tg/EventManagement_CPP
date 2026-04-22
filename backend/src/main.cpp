#define _WIN32_WINNT 0x0601  // Đảm bảo hỗ trợ Windows 7 trở lên
#include "crow_all.h"
// #include <mysqlx/xdevapi.h> // Tích hợp MySQL ở bước thực tế

int main() {
    crow::SimpleApp app;

    // Khắc phục lỗi CORS khi Frontend gọi API từ port khác
    CROW_CATCHALL_ROUTE(app)
    ([](const crow::request& req, crow::response& res) {
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Access-Control-Allow-Headers", "Content-Type");
        res.end();
    });

    // 1. API GET: Lấy danh sách sự kiện
    CROW_ROUTE(app, "/api/events").methods(crow::HTTPMethod::Get)
    ([]() {
        crow::json::wvalue json_data;
        json_data["status"] = "success";
        json_data["data"][0]["id"] = 1;
        json_data["data"][0]["title"] = "Hội thảo AI 2026";
        json_data["data"][0]["location"] = "TP. Hồ Chí Minh"; 

        // Đóng gói JSON và nhét thêm "giấy thông hành" CORS vào
        crow::response res(json_data);
        res.add_header("Access-Control-Allow-Origin", "*");
        return res;
    });

    // 2. API POST: Tạo sự kiện mới
    CROW_ROUTE(app, "/api/events").methods(crow::HTTPMethod::Post)
    ([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body) return crow::response(400, "Invalid JSON");

        std::string title = body["title"].s();
        std::string location = body["location"].s();

        // Thực tế: Insert 'title' và 'location' vào MySQL

        return crow::response(201, "{\"message\": \"Thêm sự kiện thành công\"}");
    });

    // Chạy server tại localhost:8080
    app.port(8080).multithreaded().run();
}