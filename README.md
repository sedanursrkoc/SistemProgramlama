# BASE54
Base54 kripto programı derleme ve kullanımı 

![base54-help](https://i.ibb.co/xM9py6K/base54-h.png)

## Ekip Üyeleri

* Sedanur Sarıkoç<br>
* Merve Sarı<br>
* Kübra Yılmaz<br>
* Oğuzhan Yanık<br><br>


#### DERLEME:<br>

Makefile dosyasının buluduğu dizinde derleme işlemini gerçekleştirmek için:<br>

`make` : Program derlenerek kripto isimli binary (executable) dosya oluşur.<br>

`make clean` : Derleme esnasında oluşan tüm dosyaları siler(.o uzantılı dosyalar, kripto, vb).<br>

`make cleanall` : Derleme sırasında olşan dosyaların yanı sıra; .kilit, encripted, decripted,
ornek_metin isimli dosyalar ve .txt uzantılı dosyalar var ise hepsini siler.<br>

`make run` : clean ile temizler, make ile derler ve iki komutuda (-e,- d) sırasıyla çalıştırarak 
"istiklal_marsi_2.txt" isimli dosyayı sırasıyla şifreleyerek ve çözümleyerek encripted ve decripted dosyaları üretir.<br><br>

#### KOMUTLAR:<br>

Make ile derleme işlemi gerçekleştirildikten sonra kullanılabilecek komutlar:<br>

`./kripto -h`<br>
  > Program bilgilerini ve kullanımını içeren menü gösterilir.<br>
   
  <br>

  
`./kripto -e input_file output_file`<br>
  > Dosya şifreleme yapılmak istendiğinde kullanılacak komuttur. Verilen input_file .kilit dosyasına göre şifrelenerek output_file dosyası oluşturulur ve input_file dosyasının şifrelenmiş hali bu dosyaya yazdırılır.<br>
  <sub>input_file: şifrelenmek istenen dosyanın adı</sub><br>
  <sub>output_file: şifrelenmiş dosyanın adı</sub><br>
  
  <br>
  
`./kripto -d input_file output_file`<br>
  > Dosya çözümlenmek istendiğinde kullanılacak komuttur. Verilen input_file .kilit dosyasına göre çözümlenerek output_file dosyası oluşturulur ve input_file dosyasının çözümlenmiş hali bu dosyaya yazdırılır.<br>
  <sub>input_file: şifrelenmiş dosyanın adı</sub><br>
  <sub>output_file: çözümlenmiş dosyanın adı</sub><br>
  
  <br>
  
  Farklı dizindeki dosyalar için kullanım şekli:<br>
  
 `./kripto -e dizin/input_file dizin/output_file`<br>
 `./kripto -d dizin/input_file dizin/output_file`<br>
  
