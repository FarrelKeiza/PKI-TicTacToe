
def main():
    a = int(input('Input random integer: '))
    if a % 2 == 0:
        print(a, 'adalah bilangan genap')
    else:
        print(a, 'adalah bilangan ganjil')


b = 1
while b == 1:
    main()
    b = input('Apakah mau coba lagi(Y/N)')
    if b == 'Y':
        b = 1
    else:
        b = 0
