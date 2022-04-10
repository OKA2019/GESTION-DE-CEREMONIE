DROP DATABASE IF EXISTS `examenCavance`;

CREATE DATABASE examenCavance;

USE examenCavance;

DROP TABLE IF EXISTS `Menu`;
CREATE TABLE `Menu` (
  `iden_menu` int unsigned NOT NULL AUTO_INCREMENT,
  `entrer` varchar(250) NOT NULL,
  `plat` varchar(250) NOT NULL,
  `dessert` varchar(250) DEFAULT NULL,
  PRIMARY KEY (`iden_menu`)
) ENGINE=InnoDB;

DROP TABLE IF EXISTS `Ceremonie`;
CREATE TABLE `Ceremonie` (
  `iden_ceromo` int unsigned NOT NULL AUTO_INCREMENT,
  `nom_ceromo` varchar(250) NOT NULL,
  `descri_ceremo` varchar(250) NOT NULL,
  `date_ceremo` INT NOT NULL,
  `date_debut` int DEFAULT NULL,
  `date_fin` int DEFAULT NULL,
  `num_menu` int unsigned NOT NULL,
  PRIMARY KEY (`iden_ceromo`),
  FOREIGN KEY (`num_menu`) REFERENCES `Menu` (`iden_menu`)
) ENGINE=InnoDB;

DROP TABLE IF EXISTS `Invite`;
CREATE TABLE `Invite` (
  `id_invite` int unsigned NOT NULL AUTO_INCREMENT,
  `nom` varchar(30) NOT NULL,
  `prenoms` varchar(100) NOT NULL,
  `age` int(3) NOT NULL,
  `contact` varchar(10) DEFAULT NULL,
  `residence` varchar(100) DEFAULT NULL,
  `sexe` tinyint(1) NOT NULL DEFAULT '0',
  `num_table` int(11) NOT NULL,
  `num_siege` int(11) NOT NULL,
  `num_ceromo` int unsigned NOT NULL,
  PRIMARY KEY (`id_invite`),
  FOREIGN KEY (`num_ceromo`) REFERENCES `Ceremonie` (`iden_ceromo`)
) ENGINE=InnoDB;
