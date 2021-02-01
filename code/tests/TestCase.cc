// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "test_matcher.hh"
#include "commuanute.hh"
#include "equipement.hh"
#include "outil.hh"
#include "contenant.hh"
#include "sac.hh"
#include <fstream>

  
  // TEST MASQUAGE
  /*equipement Rien = equipement();
  contenant fqdsgdh = contenant();
  sac KAS = sac();
  KAS.jaiQuoi();*/

// TEST METHODE COMMU
TEST_CASE("1: Vivres bien ajoutés"){ 
  communaute test = communaute("la Colline");
  equipement Rien = equipement();
  int avant = test.getNbNourriture();
  test.EnvoyerChercherDesVivres(test.getSurvivant(0), Rien);
  REQUIRE(test.getNbNourriture()>avant);
}

TEST_CASE("2: Bien malade si le survivant ne dors pas sous un abri"){
  communaute test = communaute("la Colline");
  equipement Rien = equipement();
  int avant = test.getNbNourriture();
  test.EnvoyerChercherDesVivres(test.getSurvivant(0), Rien);
  test.FaireConstruire(test.getSurvivant(1), Rien);
  test.EnvoyerChercherDesVivres(test.getSurvivant(2), Rien);
  test.FinirJour();
  REQUIRE(test.getSurvivant(0).getEtatSante());
}
// TEST SURCHARGE EST CONSTRUCTEUR EQUIPEMENT ET OUTIL
TEST_CASE("3: Test surcharge +="){
  equipement Rien = equipement();
  outil Testoutil = outil(100);
  outil Testoutil2 = outil(50);
  Testoutil += Testoutil2;
  REQUIRE(Testoutil.getDurabilite()==150);
}

TEST_CASE("4: Test surcharge +"){
  equipement Rien = equipement();
  outil Testoutil = outil(100);
  outil Testoutil2 = outil(50);
  outil aled = outil();
  aled = Testoutil + Testoutil2;
  REQUIRE(aled.getDurabilite()==150);
}
