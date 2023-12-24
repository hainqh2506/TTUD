/* bai 2: một công ty sữa muốn tri ân khách hàng, công ty in vào mỗi hộp sữa tươi một số tự nhiên được lấy từ một dach sách các số tự nhiên bí mật
 khác nhau cho trước. Người tiêu dùng nếu như thu thập một tập các hộp sữa tươi sao cho các số tự nhiên trong các hộp số tự nhiên này khac nhau
 và tổng của chúng lớn hơn hoặc bằng năm thành lập công ty và chia hết cho 5 thì sẽ được tặng thêm quà là 1 hộp sữa tươi. Hỏi có bao nhiêu cách thu thập các hộp
 sữa khác nhau có thể đổi được quà.
 hai cách được gọi là khác nhau, nếu tập hợp các số tự nhiên trên các hộp sữa là khác nhau.
 Dữ liệu vào:
  dòng 1: chứa 1 số nguyên n (1 <= n <= 20) số lượng phần tử trong danh sách là số tự nhiên bí mật
  dòng 2: chứa n số tự nhiên, cách nhau bởi dấu cách, có giá trị nhỏ hơn 2000, là các số tự nhiên bí mật in trên hộp sữa
  dòng 3: chứa 1 số tự nhiên là năm thành lập công ty, số này <2023
   kq:
   1 số tự nhiên duy nhất là số lượng các cách khác nhau */
   /* ví dụ:
input :
4
1000 1600 101 200
1901

output:
2
*/
/* giải thích ví dụ: kết quả bằng 2,
     vì có 2 tập hợp thoả mãn tổng các phần tử ít nhẩ 1901 và chia hết cho 5 là {1000, 1600} và {1000,1600,200}*/
 