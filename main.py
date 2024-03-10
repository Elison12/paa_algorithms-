consumo = int(input())

if consumo <= 25:
      print('35.00\n1.35')
elif consumo >= 26 and consumo <= 99:
   print('{:.2f}\n{}'.format(consumo*1.35,1.35))
elif consumo < 99:
   KWh = consumo * 1.35
   print('%.2f'%KWh )
   print ("1.35")
elif consumo >= 100 and consumo <= 299:
   print('{:.2f}\n{}'.format(consumo*1.55,1.55))
elif consumo >= 300 and consumo <= 574:
  print('{:.2f}\n{}'.format((consumo*1.75)*1.1,1.75))
elif consumo >= 575:
  print('{:.2f}\n{}'.format((consumo*2.15)*1.1,2.15))
