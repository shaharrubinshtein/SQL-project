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
-- Table structure for table `customerorderline`
--

DROP TABLE IF EXISTS `customerorderline`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customerorderline` (
  `orderLineId` int(11) NOT NULL AUTO_INCREMENT,
  `bookOrderId` int(11) NOT NULL,
  `orderId` int(11) NOT NULL,
  `lineStatus` int(11) NOT NULL,
  `quantity` int(11) NOT NULL,
  `price` float NOT NULL,
  `opDate` date DEFAULT NULL,
  PRIMARY KEY (`orderLineId`),
  KEY `bookOrderId` (`bookOrderId`),
  KEY `orderId` (`orderId`),
  CONSTRAINT `customerorderline_ibfk_1` FOREIGN KEY (`bookOrderId`) REFERENCES `bookorderline` (`orderId`),
  CONSTRAINT `customerorderline_ibfk_2` FOREIGN KEY (`orderId`) REFERENCES `customerorder` (`orderId`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customerorderline`
--

LOCK TABLES `customerorderline` WRITE;
/*!40000 ALTER TABLE `customerorderline` DISABLE KEYS */;
INSERT INTO `customerorderline` VALUES (1,1,1,1,3,150,'2017-01-10'),(2,5,2,1,6,211.875,'2017-01-15'),(3,6,2,1,2,211.875,'2017-01-15'),(4,11,3,1,1,229.5,'2017-02-10'),(5,17,4,2,1,225,'2017-01-17'),(6,19,5,1,10,204,'2015-02-17'),(7,20,6,1,20,300,'2013-02-01'),(8,21,7,1,3,202.5,'2013-05-04'),(9,22,8,1,1,405,'2017-04-06'),(10,22,9,1,1,405,'2017-04-07'),(11,22,10,1,1,405,'2017-04-08');
/*!40000 ALTER TABLE `customerorderline` ENABLE KEYS */;
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
