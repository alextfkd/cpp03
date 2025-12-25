/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 07:44:00 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/25 03:57:40 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// ClapTrap::kType_ = "ClapTrap";

ClapTrap::ClapTrap()
    : kType_("ClapTrap"),
      name_("default"),
      hit_points_(ClapTrap::kDefaultHitPoints_),
      energy_points_(ClapTrap::kDefaultEnPoints_),
      attack_damage_(ClapTrap::kDefaultAttackDamages_) {}

ClapTrap::ClapTrap(const std::string& name)
    : kType_("ClapTrap"),
      name_(name),
      hit_points_(ClapTrap::kDefaultHitPoints_),
      energy_points_(ClapTrap::kDefaultEnPoints_),
      attack_damage_(ClapTrap::kDefaultAttackDamages_) {}

ClapTrap::ClapTrap(const ClapTrap& other) : kType_(other.kType_) {
  this->name_          = other.name_;
  this->hit_points_    = other.hit_points_;
  this->energy_points_ = other.energy_points_;
  this->attack_damage_ = other.attack_damage_;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  if (this != &other) {
    this->name_          = other.name_;
    this->hit_points_    = other.hit_points_;
    this->attack_damage_ = other.attack_damage_;
    this->energy_points_ = other.energy_points_;
  }
  return *this;
}

ClapTrap::~ClapTrap() {}

bool ClapTrap::checkHitPoints_(void) {
  std::string kMsgNoHitPoints_ =
      "ClapTrap " + this->name_ +
      " can’t do anything if it has no hit points left.";
  if (this->hit_points_ > 0) {
    return true;
  }
  std::cout << kMsgNoHitPoints_ << std::endl;
  return false;
}

bool ClapTrap::useEnergyPoints_(void) {
  std::string kMsgNoEnergy_ =
      "ClapTrap " + this->name_ +
      " can’t do anything if it has no energy points left.";
  if (this->energy_points_ > 0) {
    this->energy_points_--;
    return true;
  }
  std::cout << kMsgNoEnergy_ << std::endl;
  return false;
}

void ClapTrap::attack(const std::string& target) {
  if (!this->checkHitPoints_()) {
    return;
  }
  if (!this->useEnergyPoints_()) {
    return;
  }
  std::cout << this->getName() << " attacks " << target << ", causing "
            << this->attack_damage_ << " points of damage !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!this->checkHitPoints_()) {
    return;
  }
  if (!this->useEnergyPoints_()) {
    return;
  }
  std::cout << this->getName() << " is repaired. "
            << "The hit points recovered by " << amount << "!" << std::endl;
  if (this->hit_points_ > ClapTrap::kUINT_MAX_ - amount) {
    this->hit_points_ = ClapTrap::kUINT_MAX_;
    return;
  }
  this->hit_points_ += amount;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->hit_points_ == 0) {
    std::cout << this->getName() << " has no hit points left!" << std::endl;
    return;
  }
  std::cout << this->getName() << " takes " << amount << " damage!"
            << std::endl;
  if (this->hit_points_ < amount) {
    this->hit_points_ = 0;
    return;
  }
  this->hit_points_ -= amount;
}

void ClapTrap::showStatus(void) const {
  std::cout << this->getName() << " HP: " << this->hit_points_
            << " EN: " << this->energy_points_
            << " ATK: " << this->attack_damage_ << std::endl;
}

std::string ClapTrap::getName(void) const {
  return this->kType_ + " " + this->name_;
}
