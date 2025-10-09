class ComplexNumberMultiplier:
    def multiply(self, num1: str, num2: str) -> str:
        def parse_complex(num: str):
            # Ensure the string ends with 'i'
            if not num or num[-1].lower() != 'i':
                raise ValueError("Invalid complex number format: must end with 'i'")

            # Find the first '+' or '-' (not at the start) that splits real and imaginary parts
            split_pos = None
            for i in range(1, len(num) - 1):  # exclude trailing 'i'
                if num[i] in ['+', '-'] and num[i - 1] not in ('e', 'E'):
                    split_pos = i
                    break
            if split_pos is None:
                raise ValueError("Invalid complex number format")

            real = int(num[:split_pos])
            imag = int(num[split_pos:-1])  # exclude trailing 'i'
            return real, imag

        a, b = parse_complex(num1)
        c, d = parse_complex(num2)

        # Multiply complex numbers: (a+bi)*(c+di) = (ac-bd) + (ad+bc)i
        real = a * c - b * d
        imag = a * d + b * c

        return f"{real}+{imag}i"


if __name__ == '__main__':
    multiplier = ComplexNumberMultiplier()
    num1 = input("Enter the first complex number (format: a+bi): ").strip()
    num2 = input("Enter the second complex number (format: a+bi): ").strip()

    result = multiplier.multiply(num1, num2)

    print("Result of multiplication:", result)
