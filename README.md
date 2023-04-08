# # TDVerification
#### Video Demo: https://youtu.be/4WXS1louUw4
#### Description:
TDVerification is an application designed to validate various travel document types based on checksums
set by the ICAO (International Civil Aviation Organization).
ICAO is an organization that sets standards for travel document verifications through checksums.
These checksums are important because they check for invalid/illegal passports
and bar the holders from travelling with potentially false credentials.

There are a total of 5 travel document types. They are passport, Travel Document No. 1 and 2, and Visa Types A and B.
Each travel document type is unique, so the application requires creating functions for each specific type.
For example, the passport type contains 88 characters, but the Travel Document Type 1 contains 99 characters.
I also implemented an auto-detect for those who are unsure of their travel document type.

The application works like this:

1. It opens a file explorer that allows you to select a .txt file.
    - If the file is unopenable, an error is returned
2. It compares the country codes present with the country codes that are stored in an array, via binary search.
    - It returns an error if the country code DNE, or does not exist.
3. It takes the text in the .txt file and converts the numeric characters into int versions of themselves
and it converts alphabetical characters into their corresponding ASCII values
    - This is important, as we will need to use this for checksums
4. It performs the checksum on the passport
5. For auto-detect, the type is detected by the first letter in the .txt file

The checksum deserves its own section. The check sum works by multiplying the characters in the string by a
repeating pattern of 7. 3. 1. For example, if we were to input 1, 2, 3, the values returned is 7, 6, 3.
The checksum is then checked by adding up all of the multiplyed numbers and then performing modulo 10 on the sum.
If the result is the checksum number, then the checksum is correct. If the checksum is not that number, then the checksum failed, and
the travel document is invalid or fake. This is repeated, as there are multiple sequences with checksums at the
end of each. Finally, there is the total checksum, which includes the smaller checksums. If the travel document
makes it past this stage, it is a valid document.

I have provided no samples, as it may be illegal for me to share them. However, you can try to check your
own passport or create your own samples according to the ICAO specs.

- Passport Specs: https://www.icao.int/publications/Documents/9303_p4_cons_en.pdf
- Travel Document No. 1: https://www.icao.int/publications/Documents/9303_p5_cons_en.pdf
- Travel Document No. 2: https://www.icao.int/publications/Documents/9303_p6_cons_en.pdf
- Visa Types A and B: https://www.icao.int/publications/Documents/9303_p7_cons_en.pdf

The application will only take .txt files one at a time. The features are:
- Support for passport types, Travel Document No. 1 and 2, and Visa Types A and B
- An auto-detect function which will automatically determine what travel document type the text file is
- Tells you where the checksum failed in the travel document
- Checks for invalid countries
- Only supports Windows
