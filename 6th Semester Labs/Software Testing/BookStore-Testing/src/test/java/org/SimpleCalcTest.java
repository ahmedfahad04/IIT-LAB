package org;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SimpleCalcTest {

    @Test
    void TwoPlusTwoShouldBeFour(){
        SimpleCalc calc = new SimpleCalc();
        assertEquals(4, calc.add(2,2));
    }

    @Test
    void ThreePlusSevenShouldBeTen(){
        SimpleCalc calc = new SimpleCalc();
        assertEquals(10, calc.add(3,7));
    }

    @Test
    void TestIfItIsACalculator() {
        var calc = new SimpleCalc();
        assertTrue(calc.isCalc());
    }

}