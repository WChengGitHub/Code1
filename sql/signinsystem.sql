/*
Navicat MySQL Data Transfer

Source Server         : mysql
Source Server Version : 50717
Source Host           : localhost:3306
Source Database       : signinsystem

Target Server Type    : MYSQL
Target Server Version : 50717
File Encoding         : 65001

Date: 2017-03-29 15:45:22
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for tb_activity
-- ----------------------------
DROP TABLE IF EXISTS `tb_activity`;
CREATE TABLE `tb_activity` (
  `ActivityId` char(32) NOT NULL,
  `ActivityName` char(24) NOT NULL,
  `Content` varchar(100) DEFAULT NULL,
  `StartTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `EndTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `EmployeeId` char(32) NOT NULL,
  `Address` varchar(30) NOT NULL,
  PRIMARY KEY (`ActivityId`),
  KEY `EmployeeId` (`EmployeeId`),
  CONSTRAINT `tb_activity_ibfk_1` FOREIGN KEY (`EmployeeId`) REFERENCES `tb_employee` (`EmployeeId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_activity
-- ----------------------------

-- ----------------------------
-- Table structure for tb_activityattendance
-- ----------------------------
DROP TABLE IF EXISTS `tb_activityattendance`;
CREATE TABLE `tb_activityattendance` (
  `ActivityAttendanceId` char(32) NOT NULL,
  `EmployeeId` char(32) NOT NULL,
  `ActivityId` char(32) NOT NULL,
  `EnterTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `OutTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Status` char(1) NOT NULL,
  PRIMARY KEY (`ActivityAttendanceId`),
  KEY `EmployeeId` (`EmployeeId`),
  KEY `ActivityId` (`ActivityId`),
  CONSTRAINT `tb_activityattendance_ibfk_1` FOREIGN KEY (`EmployeeId`) REFERENCES `tb_employee` (`EmployeeId`),
  CONSTRAINT `tb_activityattendance_ibfk_2` FOREIGN KEY (`ActivityId`) REFERENCES `tb_activity` (`ActivityId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_activityattendance
-- ----------------------------

-- ----------------------------
-- Table structure for tb_advice
-- ----------------------------
DROP TABLE IF EXISTS `tb_advice`;
CREATE TABLE `tb_advice` (
  `AdviceId` char(32) NOT NULL,
  `EmployeeId` char(32) NOT NULL,
  `Content` varchar(100) NOT NULL,
  `Status` bit(1) NOT NULL DEFAULT b'0',
  `Date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Style` bit(1) NOT NULL,
  PRIMARY KEY (`AdviceId`),
  KEY `EmployeeId` (`EmployeeId`),
  CONSTRAINT `tb_advice_ibfk_1` FOREIGN KEY (`EmployeeId`) REFERENCES `tb_employee` (`EmployeeId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_advice
-- ----------------------------

-- ----------------------------
-- Table structure for tb_application
-- ----------------------------
DROP TABLE IF EXISTS `tb_application`;
CREATE TABLE `tb_application` (
  `ApplicationId` char(32) NOT NULL,
  `EmployeeId` char(32) NOT NULL,
  `DailyAttendanceId` char(32) NOT NULL,
  `Remark` varchar(100) NOT NULL,
  `ApplicationTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Status` bit(1) NOT NULL DEFAULT b'0',
  PRIMARY KEY (`ApplicationId`),
  KEY `EmployeeId` (`EmployeeId`),
  KEY `DailyAttendanceId` (`DailyAttendanceId`),
  CONSTRAINT `tb_application_ibfk_1` FOREIGN KEY (`EmployeeId`) REFERENCES `tb_employee` (`EmployeeId`),
  CONSTRAINT `tb_application_ibfk_2` FOREIGN KEY (`DailyAttendanceId`) REFERENCES `tb_dailyattendance` (`DailyAttendanceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_application
-- ----------------------------
INSERT INTO `tb_application` VALUES ('1', '1', '1', '777777', '2017-03-29 15:33:13', '');
INSERT INTO `tb_application` VALUES ('2', '2', '2', '4444', '2017-03-27 13:06:34', '\0');
INSERT INTO `tb_application` VALUES ('3', '3', '3', '44444', '2017-03-27 13:06:47', '\0');
INSERT INTO `tb_application` VALUES ('4', '1', '1', '444', '2017-03-23 15:32:17', '');

-- ----------------------------
-- Table structure for tb_arriveandleave
-- ----------------------------
DROP TABLE IF EXISTS `tb_arriveandleave`;
CREATE TABLE `tb_arriveandleave` (
  `ArriveAndLeaveId` char(32) NOT NULL,
  `EmployeeId` char(32) NOT NULL,
  `ArriveTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `LeaveTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`ArriveAndLeaveId`),
  KEY `EmployeeId` (`EmployeeId`),
  CONSTRAINT `tb_arriveandleave_ibfk_1` FOREIGN KEY (`EmployeeId`) REFERENCES `tb_employee` (`EmployeeId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_arriveandleave
-- ----------------------------

-- ----------------------------
-- Table structure for tb_company
-- ----------------------------
DROP TABLE IF EXISTS `tb_company`;
CREATE TABLE `tb_company` (
  `CompanyId` char(32) NOT NULL,
  `Name` varchar(100) NOT NULL,
  `Address` varchar(255) NOT NULL,
  `Del` bit(1) NOT NULL DEFAULT b'0',
  `CompanyRepresentativeId` char(32) NOT NULL,
  PRIMARY KEY (`CompanyId`),
  KEY `CompanyRepresentativeId` (`CompanyRepresentativeId`),
  CONSTRAINT `tb_company_ibfk_1` FOREIGN KEY (`CompanyRepresentativeId`) REFERENCES `tb_companyrepresentative` (`CompanyRepresentativeId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_company
-- ----------------------------
INSERT INTO `tb_company` VALUES ('1', '1', '1', '\0', '1');

-- ----------------------------
-- Table structure for tb_companyrepresentative
-- ----------------------------
DROP TABLE IF EXISTS `tb_companyrepresentative`;
CREATE TABLE `tb_companyrepresentative` (
  `CompanyRepresentativeId` char(32) NOT NULL,
  `Name` varchar(20) NOT NULL,
  `Password` varchar(20) NOT NULL,
  `Telephone` char(12) NOT NULL,
  `Email` varchar(32) NOT NULL,
  PRIMARY KEY (`CompanyRepresentativeId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_companyrepresentative
-- ----------------------------
INSERT INTO `tb_companyrepresentative` VALUES ('1', '11', '1', '1', '1');

-- ----------------------------
-- Table structure for tb_dailyattendance
-- ----------------------------
DROP TABLE IF EXISTS `tb_dailyattendance`;
CREATE TABLE `tb_dailyattendance` (
  `DailyAttendanceId` char(32) NOT NULL,
  `EnterTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `OutTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `FrontTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `AccumulatedTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Status` char(1) NOT NULL,
  `EmployeeId` char(32) NOT NULL,
  PRIMARY KEY (`DailyAttendanceId`),
  KEY `EmployeeId` (`EmployeeId`),
  CONSTRAINT `tb_dailyattendance_ibfk_1` FOREIGN KEY (`EmployeeId`) REFERENCES `tb_employee` (`EmployeeId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_dailyattendance
-- ----------------------------
INSERT INTO `tb_dailyattendance` VALUES ('1', '2017-03-27 13:00:50', '0000-00-00 00:00:00', '0000-00-00 00:00:00', '0000-00-00 00:00:00', '1', '1');
INSERT INTO `tb_dailyattendance` VALUES ('2', '2017-03-27 13:05:15', '0000-00-00 00:00:00', '0000-00-00 00:00:00', '0000-00-00 00:00:00', '1', '2');
INSERT INTO `tb_dailyattendance` VALUES ('3', '2017-03-27 13:05:27', '0000-00-00 00:00:00', '0000-00-00 00:00:00', '0000-00-00 00:00:00', '1', '3');

-- ----------------------------
-- Table structure for tb_department
-- ----------------------------
DROP TABLE IF EXISTS `tb_department`;
CREATE TABLE `tb_department` (
  `DepartmentId` char(32) NOT NULL,
  `Name` varchar(30) NOT NULL,
  `CompanyId` char(32) NOT NULL,
  `Address` varchar(100) NOT NULL,
  `Mac` char(18) NOT NULL,
  PRIMARY KEY (`DepartmentId`),
  KEY `CompanyId` (`CompanyId`),
  CONSTRAINT `tb_department_ibfk_1` FOREIGN KEY (`CompanyId`) REFERENCES `tb_company` (`CompanyId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_department
-- ----------------------------
INSERT INTO `tb_department` VALUES ('1', '1', '1', '1', '111');

-- ----------------------------
-- Table structure for tb_detail
-- ----------------------------
DROP TABLE IF EXISTS `tb_detail`;
CREATE TABLE `tb_detail` (
  `DetailId` char(32) NOT NULL,
  `Status` char(1) NOT NULL,
  `StartTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `EndTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `AcceptTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Reason` varchar(200) NOT NULL,
  `EmployeeId` char(32) NOT NULL,
  `Date` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Address` varchar(100) DEFAULT NULL,
  `Style` bit(1) NOT NULL DEFAULT b'0',
  PRIMARY KEY (`DetailId`),
  KEY `EmployeeId` (`EmployeeId`),
  CONSTRAINT `tb_detail_ibfk_1` FOREIGN KEY (`EmployeeId`) REFERENCES `tb_employee` (`EmployeeId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_detail
-- ----------------------------

-- ----------------------------
-- Table structure for tb_employee
-- ----------------------------
DROP TABLE IF EXISTS `tb_employee`;
CREATE TABLE `tb_employee` (
  `EmployeeId` char(32) NOT NULL,
  `Name` varchar(20) NOT NULL,
  `Account` varchar(30) NOT NULL,
  `Password` varchar(20) NOT NULL,
  `Del` bit(1) NOT NULL DEFAULT b'0',
  `Telephone` char(12) NOT NULL,
  `Sex` bit(1) NOT NULL,
  `Email` varchar(32) NOT NULL,
  `DepartmentId` char(32) NOT NULL,
  `Duties` varchar(20) NOT NULL,
  `Privilege` char(1) NOT NULL,
  PRIMARY KEY (`EmployeeId`),
  KEY `DepartmentId` (`DepartmentId`),
  CONSTRAINT `tb_employee_ibfk_1` FOREIGN KEY (`DepartmentId`) REFERENCES `tb_department` (`DepartmentId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_employee
-- ----------------------------
INSERT INTO `tb_employee` VALUES ('1', '1', '1', '1', '\0', '111', '', '1', '1', '11', '1');
INSERT INTO `tb_employee` VALUES ('2', '2', '1', '1', '\0', '111', '', '1', '1', '11', '1');
INSERT INTO `tb_employee` VALUES ('3', '3', '1', '1', '\0', '1', '', '1', '1', '11', '1');

-- ----------------------------
-- Table structure for tb_employeenotify
-- ----------------------------
DROP TABLE IF EXISTS `tb_employeenotify`;
CREATE TABLE `tb_employeenotify` (
  `NotifyId` char(32) NOT NULL,
  `EmployeeId` char(32) NOT NULL,
  PRIMARY KEY (`NotifyId`,`EmployeeId`),
  KEY `EmployeeId` (`EmployeeId`),
  CONSTRAINT `tb_employeenotify_ibfk_1` FOREIGN KEY (`EmployeeId`) REFERENCES `tb_employee` (`EmployeeId`),
  CONSTRAINT `tb_employeenotify_ibfk_2` FOREIGN KEY (`NotifyId`) REFERENCES `tb_notify` (`NotifyId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_employeenotify
-- ----------------------------

-- ----------------------------
-- Table structure for tb_memo
-- ----------------------------
DROP TABLE IF EXISTS `tb_memo`;
CREATE TABLE `tb_memo` (
  `MemoId` char(32) NOT NULL,
  `EmployeeId` char(32) NOT NULL,
  `Content` varchar(200) NOT NULL,
  `StartTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `EndTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`MemoId`),
  KEY `EmployeeId` (`EmployeeId`),
  CONSTRAINT `tb_memo_ibfk_1` FOREIGN KEY (`EmployeeId`) REFERENCES `tb_employee` (`EmployeeId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_memo
-- ----------------------------

-- ----------------------------
-- Table structure for tb_notify
-- ----------------------------
DROP TABLE IF EXISTS `tb_notify`;
CREATE TABLE `tb_notify` (
  `NotifyId` char(32) NOT NULL,
  `Content` varchar(100) NOT NULL,
  `NotifyTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`NotifyId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_notify
-- ----------------------------

-- ----------------------------
-- Table structure for tb_schedule
-- ----------------------------
DROP TABLE IF EXISTS `tb_schedule`;
CREATE TABLE `tb_schedule` (
  `ScheduleId` char(32) NOT NULL,
  `EmployeeId` char(32) NOT NULL,
  `EnterTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `OutTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`ScheduleId`),
  KEY `EmployeeId` (`EmployeeId`),
  CONSTRAINT `tb_schedule_ibfk_1` FOREIGN KEY (`EmployeeId`) REFERENCES `tb_employee` (`EmployeeId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tb_schedule
-- ----------------------------
