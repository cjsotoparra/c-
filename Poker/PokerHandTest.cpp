//
// Created by Rick Mercer on 2019-03-20.
//

// Beginning of a Unit test for PokerHand and its overloaded < operator
#include "PokerHand.hpp"
#include "52Cards.hpp"
#include "catch.hpp"

TEST_CASE("testHighCard2") {
  PokerHand a(C3, C4, D6, D7, DQ);
  PokerHand b(C2, C5, C7, DJ, DK);


  REQUIRE(a < b);

}

// TEST PAIRS PokerHand pair(D2, H2, D3, S7, H6);
//PokerHand pair2(C2, S2, CQ, CK, CA);
//PokerHand pair3(C3, H3, H4, H5, S6);

//TEST_CASE(" testPairs2_3") {
//  REQUIRE(pair2 < pair3);
//}

//TEST_CASE ("AceLowStraight") {
  //PokerHand a(CA, C2, S3, D4, H5); // Ace low straight
  //PokerHand b(DK, HK, SK, D5, H6); // 3 of a kind
 // REQUIRE(b < a);
//}
