#include "tablecipher.h"
#include "tablecipher.cpp"
#include <UnitTest++/UnitTest++.h>
#include <locale>
#include <iostream>
#include <string>

SUITE(KeyTest) {
	TEST(ValidKey) 
    	{ tablecipher c(3);
    	CHECK_EQUAL(c.encrypt("PRIVET"), "ITREPV"); }
	TEST(InvalidKey) 
    	{ CHECK_THROW(tablecipher c(-1), cipher_error); }
    TEST(FloatKey) 
    	{ CHECK_THROW(tablecipher c(-14.02), cipher_error); }
    TEST(BigKey) 
    { 
        tablecipher c(100);
        CHECK_EQUAL("TEVIRP", c.encrypt("PRIVET"));
    }
}
SUITE(EncryptTest)
{
	
    TEST(UpString) 
    { 
        tablecipher c(3);
        CHECK_EQUAL("ITREPV", c.encrypt("PRIVET"));
    }
    TEST(LowString) 
    { 
        tablecipher c(3);
        CHECK_EQUAL("itRepV", c.encrypt("pRiVet"));
    }

    TEST(EmptyString) 
    { 
        tablecipher c(3);
        CHECK_THROW(c.encrypt(""), cipher_error);
    }

    TEST(DigestText) 
    { 
        tablecipher c(3);
        CHECK_EQUAL("IT3RE2PV1", c.encrypt("PRIVET123"));
    }
}

SUITE(DecryptTest)
{
    TEST(UpString) 
    { 
        tablecipher c(3);
        CHECK_EQUAL("PRIVET", c.decrypt("ITREPV")); 
    }
    TEST(LowString) 
    { 
        tablecipher c(3);
        CHECK_EQUAL("PRIvet", c.decrypt("ItRePv")); 
    }

    TEST(EmptyString) 
    { 
        tablecipher c(3);
        CHECK_THROW(c.decrypt(""), cipher_error);
    }
    TEST(DigestText) 
    { 
        tablecipher c(3);
        CHECK_EQUAL("1EI2PT3VR", c.decrypt("ITREPV123"));
    }
}

int main() {
    return UnitTest::RunAllTests();
}
