# Road Rumble - Game project

    Họ và Tên: Lê Nhữ Quang
    MSSV: 23021671
## *Mô tả trò chơi*

### *Giới thiệu*

* "Road Rumble" là một trò chơi mà nhân vật chính trên chiếc xe Jeep vô tình lạc vào một đường cao tốc ngược chiều dài vô hạn có những vật phẩm kỳ lạ, nhân vật chính chỉ có một mục đích duy nhất là sống sót lâu nhất có thể

### *Cách chơi*

#### 1. Giới thiệu các vật thể
*  **Người chơi** ![Idle](https://github.com/qu4ll12/SDL_Project/blob/main/Game/texture/jeep.png).
* **Xe đối địch** ![one](https://github.com/qu4ll12/SDL_Project/blob/main/Game/texture/taxi2.png).
* **TNT** ![one](https://github.com/qu4ll12/SDL_Project/blob/main/Game/texture/tnt.png).
* **Khiên** ![one](https://github.com/qu4ll12/SDL_Project/blob/main/Game/texture/shield.png).
* **Bình năng lượng** ![one](https://github.com/qu4ll12/SDL_Project/blob/main/Game/texture/energy1.png).
#### 2. Các chế độ game
* **Chế độ Easy - Normal - Hard:
  Với tốc độ và mật độ các xe chướng ngại vật tăng dần

#### 3. Luật chơi
* Người chơi điều khiển xe để né các vật cản trên đường là TNT và xe đối địch.
* Cách thức các vật thể hoạt động:
   * TNT khiến xe người chơi phát nổ.
   * Khiên sẽ tạo cho người chơi một lớp giáp giúp chống lại TNT (nhưng không cản được xe đối địch).
   * Bình năng lượng sẽ hồi lại thanh năng lượng cho người chơi.
* Để tăng score thì người chơi có các cách như sau:
   * Lách được càng nhiều xe càng tốt.
   * Ăn các bình năng lượng.
   * Dính TNT trong khi đang mang khiên.
* Các cách thức người chơi có thể thua:
   * Đâm phải TNT khi không có khiên
   * Hết thanh năng lượng
   * Bị xe đối địch tông

#### 4. Các phím thao tác
* Người chơi sử dụng bàn phím máy tính để điều khiển nhân vật.

    | Chức năng  | Phím |
    | ------------- |:-------------:| 
    | Di chuyển sang trái    | A    |
    | Di chuyển sang phải    | D    |
  
* Các thao tác trò chơi
    * Bật Setting trong lúc chơi: sử dụng phím Esc.
    * Chỉnh âm thanh, độ khó trong Setting: kéo thả chuột.
    
## *Hình ảnh minh họa*

### Start Menu
![image](https://github.com/qu4ll12/SDL_Project/assets/158488809/6be6d791-9632-4fc0-b771-3df61be92a9c)

* **[Video demo trò chơi](https://youtu.be/7YNWx59XnYE)**
## *Các kĩ thuật sử dụng*
### SDL
* Tương tác mượt mà với chuột và bàn phím.
* Sử dụng các kĩ thuật để render hình ảnh, âm thanh, text.
* Sử dụng các kĩ thuật để xoay, hiện hoạt ảnh một cách đơn giản và dễ dàng.

### C++
* Sử dụng các kiến thức về: Vector, Random, Class, Ifstream, Vòng lặp, Mảng...

### Kĩ thuật khác
* Khởi tạo Menu với các nút bấm và thanh kéo: Play, Resume, Setting, Exit, Instruction, Information, Slide.
* Tối giản hàm main dễ dọc, dễ hiểu.
* Tách code thành nhiều hàm.
* Sử dụng thuật toán để render các vật thể không chồng chéo lên nhau sau các lần random spawn.

## *Nguồn tham khảo*
* Nguồn hình ảnh: Chủ yếu tự vẽ, tham khảo một số trên pinterest.com và vẽ lại.
* Nguồn âm thanh: pixabay.com, youtube.com
* Cách sử dụng (có code mẫu) thư viện SDL2: code của cô Trần Thị Minh Châu

## *Kết luận*
* Dự án game SDL2 đã mang đến cho em nhiều bài học quý giá về lập trình game và sử dụng thư viện SDL2:

* Kiến thức về lập trình game: Em đã nắm vững các khái niệm cơ bản về lập trình game, áp dụng các kỹ thuật lập trình hướng đối tượng, con trỏ, tìm hiểu về đồ họa 2D, quản lý âm thanh và sự kiện, tối ưu hóa hiệu suất game.
*Khả năng sử dụng thư viện SDL2: Em đã thành thạo các chức năng cơ bản của SDL2, sử dụng các file và truyền file, gỡ lỗi và tối ưu hóa ứng dụng SDL2.
*Kinh nghiệm thực tế: em đã trải qua quá trình phát triển game đầy đủ, quản lý dự án, và học hỏi nhiều điều về việc sáng tạo đồ hoạ.
*Dự án này giúp em phát triển kiến thức, kỹ năng và kinh nghiệm cần thiết cho sự nghiệp lập trình game trong tương lai.

## *Lời cuối*
*Cảm ơn mọi người đã đọc và đánh giá project đầu tiên của em.*

#### **Mức điểm tự đánh giá: 8.5 - 9.5.**
