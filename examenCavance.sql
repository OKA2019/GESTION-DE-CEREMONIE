-- MySQL dump 10.13  Distrib 8.0.28, for Linux (x86_64)
--
-- Host: localhost    Database: examenCavance
-- ------------------------------------------------------
-- Server version	8.0.28-0ubuntu0.20.04.3

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Ceremonie`
--

DROP TABLE IF EXISTS `Ceremonie`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Ceremonie` (
  `iden_ceromo` int unsigned NOT NULL AUTO_INCREMENT,
  `nom_ceromo` varchar(250) NOT NULL,
  `descri_ceremo` varchar(250) NOT NULL,
  `date_ceremo` int NOT NULL,
  `date_debut` int DEFAULT NULL,
  `type` int unsigned NOT NULL,
  `num_menu` int unsigned NOT NULL,
  PRIMARY KEY (`iden_ceromo`),
  KEY `num_menu` (`num_menu`),
  CONSTRAINT `Ceremonie_ibfk_1` FOREIGN KEY (`num_menu`) REFERENCES `Menu` (`iden_menu`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Ceremonie`
--

LOCK TABLES `Ceremonie` WRITE;
/*!40000 ALTER TABLE `Ceremonie` DISABLE KEYS */;
INSERT INTO `Ceremonie` VALUES (1,'reunion','travail',604800,604800,1,1),(4,'UNION DU COUPLE DIEKÉ','Mariage de Dieké et Traoré',1652411225,1652411225,2,1),(5,'MARIAGE','Union de Dieke et Louisette',632918016,632918016,2,3),(6,'REUNION','Seance de travail de la SIGKL 2022',1650010632,1650010632,3,3),(7,'MARAIGE','Union des Yeo',1651448628,1651448628,2,3),(8,'DINÉ GALA','Soirée entre de la IT7',1653273422,1653273422,3,2),(9,'LANGAGE C','Examen de langage c avancé',1652839943,1652839943,1,3);
/*!40000 ALTER TABLE `Ceremonie` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Invite`
--

DROP TABLE IF EXISTS `Invite`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Invite` (
  `id_invite` int unsigned NOT NULL AUTO_INCREMENT,
  `nom` varchar(30) NOT NULL,
  `prenoms` varchar(100) NOT NULL,
  `age` int NOT NULL,
  `contact` varchar(10) DEFAULT NULL,
  `residence` varchar(100) DEFAULT NULL,
  `sexe` tinyint(1) NOT NULL DEFAULT '0',
  `num_table` int NOT NULL,
  `num_siege` int NOT NULL,
  `num_ceromo` int unsigned NOT NULL,
  `entrer` varchar(250) DEFAULT NULL,
  `plat` varchar(250) DEFAULT NULL,
  `dessert` varchar(250) DEFAULT NULL,
  PRIMARY KEY (`id_invite`),
  KEY `num_ceromo` (`num_ceromo`),
  CONSTRAINT `Invite_ibfk_1` FOREIGN KEY (`num_ceromo`) REFERENCES `Ceremonie` (`iden_ceromo`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Invite`
--

LOCK TABLES `Invite` WRITE;
/*!40000 ALTER TABLE `Invite` DISABLE KEYS */;
INSERT INTO `Invite` VALUES (4,'OUATTARA','KOUNAPETRI ABDOULAYE',22,'0747963654','FERKE',1,5,1,7,'salade','riz avec poulet','mangue'),(5,'KAMATE','FANTA',25,'01010101','Abidjan',0,1,5,8,'mangue','frites','mangue'),(6,'OUATTARA','SIENFANI',28,'0749857569','Katiola',0,2,1,8,'mangue','frites','salade');
/*!40000 ALTER TABLE `Invite` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Menu`
--

DROP TABLE IF EXISTS `Menu`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Menu` (
  `iden_menu` int unsigned NOT NULL AUTO_INCREMENT,
  `entrer` varchar(250) NOT NULL,
  `plat` varchar(250) NOT NULL,
  `dessert` varchar(250) DEFAULT NULL,
  PRIMARY KEY (`iden_menu`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Menu`
--

LOCK TABLES `Menu` WRITE;
/*!40000 ALTER TABLE `Menu` DISABLE KEYS */;
INSERT INTO `Menu` VALUES (1,'salde, mangue','foutou sauce gombo','orange, mangue, salade'),(2,'salade, mangue','Foutou avec poulet, frites avec mouton','mangue, salade, orange, banane'),(3,'salade','Riz sauce graine','mangue');
/*!40000 ALTER TABLE `Menu` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gestionnaire`
--

DROP TABLE IF EXISTS `gestionnaire`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `gestionnaire` (
  `id_gestion` int unsigned NOT NULL AUTO_INCREMENT,
  `nom_gestion` varchar(50) NOT NULL,
  `pass_gestion` varchar(50) NOT NULL,
  PRIMARY KEY (`id_gestion`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `gestionnaire`
--

LOCK TABLES `gestionnaire` WRITE;
/*!40000 ALTER TABLE `gestionnaire` DISABLE KEYS */;
INSERT INTO `gestionnaire` VALUES (1,'OKA','1234');
/*!40000 ALTER TABLE `gestionnaire` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-05-06 11:24:16
