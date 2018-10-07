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
-- Table structure for table `bookorderline`
--

DROP TABLE IF EXISTS `bookorderline`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bookorderline` (
  `orderId` int(11) NOT NULL AUTO_INCREMENT,
  `bookId` int(11) NOT NULL,
  `supplierId` int(11) NOT NULL,
  `quantity` int(11) NOT NULL,
  `orderLineStatus` int(11) NOT NULL,
  `bookCost` float NOT NULL,
  `currentStock` int(11) NOT NULL,
  `inDate` date NOT NULL,
  PRIMARY KEY (`orderId`),
  KEY `bookId` (`bookId`),
  KEY `supplierId` (`supplierId`),
  CONSTRAINT `bookorderline_ibfk_1` FOREIGN KEY (`bookId`) REFERENCES `suppliercatalog` (`bookId`),
  CONSTRAINT `bookorderline_ibfk_2` FOREIGN KEY (`supplierId`) REFERENCES `suppliercatalog` (`supplierId`)
) ENGINE=InnoDB AUTO_INCREMENT=23 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bookorderline`
--

LOCK TABLES `bookorderline` WRITE;
/*!40000 ALTER TABLE `bookorderline` DISABLE KEYS */;
INSERT INTO `bookorderline` VALUES (1,1,1001,5,1,100,4,'2017-01-01'),(2,1,1002,3,1,100,3,'2017-01-01'),(5,4,1001,6,1,150,0,'2017-01-01'),(6,4,1002,2,1,115,0,'2017-01-01'),(7,6,1001,5,1,130,5,'2017-01-01'),(8,6,1002,5,1,134,5,'2017-01-01'),(9,8,1001,5,1,120,5,'2017-01-01'),(10,8,1002,5,1,100,5,'2017-01-01'),(11,10,1001,5,1,200,4,'2017-01-01'),(12,10,1002,5,1,140,5,'2017-01-01'),(13,12,1001,5,1,80,5,'2017-01-01'),(14,12,1002,5,1,50,5,'2017-01-01'),(15,14,1001,5,1,170,5,'2017-01-01'),(16,14,1002,5,1,70,5,'2017-01-01'),(17,4,1001,1,2,150,0,'2017-01-17'),(18,1,1001,1,1,100,1,'2017-03-01'),(19,14,1001,10,1,170,0,'2015-02-16'),(20,10,1001,20,1,200,0,'2013-01-20'),(21,17,1010,3,1,150,0,'2013-05-04'),(22,15,1009,4,1,300,1,'2017-04-04');
/*!40000 ALTER TABLE `bookorderline` ENABLE KEYS */;
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
