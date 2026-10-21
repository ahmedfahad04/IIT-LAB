package org;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class GraderTest {

    // here using only one method
    // we are covering at most 43%
    // not all of the lines are covered
    // so we need to write test cases for
    // each condition

    @Test
    void NegativeOneShouldReturnIllegalArgException() {
        var grade = new Grader();
        assertThrows(IllegalArgumentException.class, ()->{grade.determineLetterGrade(-1);});
    }

    @Test
    void fiftyNineShouldReturnF() {
        var grade = new Grader();
        assertEquals('F', grade.determineLetterGrade(59));
    }

    @Test
    void SixtyNineShouldReturnD() {
        var grade = new Grader();
        assertEquals('D', grade.determineLetterGrade(69));
    }

    @Test
    void SeventyNineShouldReturnC() {
        var grade = new Grader();
        assertEquals('C', grade.determineLetterGrade(79));
    }

    @Test
    void EightyNineShouldReturnB() {
        var grade = new Grader();
        assertEquals('B', grade.determineLetterGrade(89));
    }

    @Test
    void NinetyNineShouldReturnA() {
        var grade = new Grader();
        assertEquals('A', grade.determineLetterGrade(99));
    }



}