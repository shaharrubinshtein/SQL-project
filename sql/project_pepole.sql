-- MySQL dump 10.13  Distrib 5.7.17, for Win64 (x86_64)
--
-- Host: localhost    Database: project
-- ------------------------------------------------------
-- Server version	5.7.21-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `pepole`
--

DROP TABLE IF EXISTS `pepole`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pepole` (
  `id` int(11) NOT NULL,
  `fisrtName` varchar(20) NOT NULL,
  `lastName` varchar(20) NOT NULL,
  `city` varchar(30) NOT NULL,
  `phoneNumber` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pepole`
--

LOCK TABLES `pepole` WRITE;
/*!40000 ALTER TABLE `pepole` DISABLE KEYS */;
INSERT INTO `pepole` VALUES (302999001,'Nir','Adler','Holon',545338001),(302999002,'Joanne','Rowling','Tel Aviv',545338002),(302999003,'yoni','dagan','bat yam',545338003),(302999004,'karin','halika','Ramat Gan',545338004),(302999005,'danial','hafuta','jerusalem',545338005),(302999006,'eyal','almog','jerusalem',545338006),(302999007,'hava','halika','jerusalem',545338007),(302999008,'dorit','alon','biez zayit',545338008),(302999009,'yarin','choen','Tel Aviv',545338009),(302999010,'moria','danino','Tel Aviv',545338010),(302999011,'John','Tolkien','Tel Aviv',545338011),(302999012,'lia','hamer','Tel Aviv',545338012),(302999013,'guy','adler','Tel Aviv',545338013),(302999014,'sahar','rob','North',545338015),(302999015,'or','aloni','North',545338016);
/*!40000 ALTER TABLE `pepole` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-08-05 18:11:27
