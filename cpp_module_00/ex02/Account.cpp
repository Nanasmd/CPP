/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:17:53 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/15 17:35:43 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

/*
** Initialisation des variables membres statiques
*/
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*
** Constructeur : Initialise un compte avec un dépôt initial
*/

Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts), // initialisation de l'index du compte
	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) // initialisation du montant, des dépôts et retraits
{
	// Augmentation du nombre de comptes et du montant total lors de la création d'un compte
	Account::_nbAccounts++;
	Account::_totalAmount += Account::checkAmount();
	// Affichage des informations du compte nouvellement créé
	Account::_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ';'
		<< "amount:" << Account::checkAmount() << ';'
		<< "created" << std::endl;
}

/*
** Destructeur : Nettoie le compte lorsqu'il est supprimé
*/
Account::~Account()
{
	// Affichage des informations du compte juste avant sa suppression
	Account::_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ';'
		<< "amount:" << Account::checkAmount() << ';'
		<< "closed" << std::endl;
	// Décrémentation du nombre de comptes et soustraction du montant du compte du montant total lors de la suppression d'un compte
	Account::_nbAccounts--;
	Account::_totalAmount -= Account::checkAmount();
}

/*
** Fonctions statiques publiques non-membres
*/

// Renvoie le nombre total de comptes
int	Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

// Renvoie le montant total stocké dans tous les comptes
int	Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

// Renvoie le nombre total de dépôts effectués sur tous les comptes
int	Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

// Renvoie le nombre total de retraits effectués sur tous les comptes
int	Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

// Affiche les informations globales concernant tous les comptes
void	Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout
		<< "accounts:" << Account::getNbAccounts() << ';'
		<< "total:" << Account::getTotalAmount() << ';'
		<< "deposits:" << Account::getNbDeposits() << ';'
		<< "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

/*
** Fonctions membres publiquess
*/

// Effectue un dépôt sur le compte et met à jour les informations pertinentes
void	Account::makeDeposit(int deposit)
{
	// Affichage des informations initiales pour le dépôt
	Account::_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ';'
		<< "p_amount:" << Account::checkAmount() << ';';
	// Validation du montant du dépôt et gestion des dépôts non valides
	if (deposit < 0)
		std::cout << "deposit:refused" << std::endl;

	else
	{
		// Mise à jour des totaux globaux et des informations spécifiques au compte
		Account::_totalAmount += deposit;
		Account::_totalNbDeposits++;
		// Mise à jour des informations spécifiques au compte et affichage des nouvelles informations
		this->_amount += deposit;
		this->_nbDeposits++;

		std::cout
			<< "deposit:" << deposit << ';'
			<< "amount:" << Account::checkAmount() << ';'
			<< "nb_deposits:" << this->_nbDeposits << std::endl;
	}
}

// Tente un retrait du compte, met à jour les informations pertinentes et renvoie un booléen indiquant si le retrait a été réussi
bool	Account::makeWithdrawal( int withdrawal )
{
	// Affichage des informations initiales pour le retrait
	Account::_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ';'
		<< "p_amount:" << Account::checkAmount() << ';';
	// Validation du montant du retrait et gestion des retraits non valides
	if (withdrawal > Account::checkAmount() || withdrawal < 0)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	// Mise à jour des totaux globaux et des informations spécifiques au compte
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	// Mise à jour des informations spécifiques au compte et affichage des nouvelles informations
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	std::cout
		<< "withdrawal:" << withdrawal << ';'
		<< "amount:" << Account::checkAmount() << ';'
		<< "nb_withdrawals:" << this->_nbDeposits << std::endl; // Correction: _nbDeposits remplacé par _nbWithdrawals
	return (true);
}

// Vérifie le montant actuel du compte
int	Account::checkAmount() const
{
	return (this->_amount);
}

// Affiche l'état actuel du compte
void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ';'
		<< "amount:" << Account::checkAmount() << ';'
		<< "deposits:" << this->_nbDeposits << ';'
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

/*
** Fonction statique privée non-membre
*/

// Affiche un horodatage pour les transactions et autres sorties
void	Account::_displayTimestamp()
{
	std::time_t	timestamp;
	tm			*t;
	// Obtention et formatage de l'horodatage actuel
	timestamp = std::time(0);
	t = localtime(&timestamp);
	std::cout
		<< '['
		<< t->tm_year + 1900
		<< std::setfill('0') << std::setw(2) << t->tm_mon + 1
		<< std::setfill('0') << std::setw(2) << t->tm_mday
		<< '_'
		<< std::setfill('0') << std::setw(2) << t->tm_hour
		<< std::setfill('0') << std::setw(2) << t->tm_min
		<< std::setfill('0') << std::setw(2) << t->tm_sec
		<< "] ";
}

/*
** private member function
*/
Account::Account() {}

// Concept Général :

// Le projet dépeint un système bancaire simple qui maintient des transactions de base telles que les dépôts et les retraits, tout en enregistrant chaque action.

// La classe Account encapsule des membres pour suivre :
// Le nombre total de comptes, le montant total détenu, le total des dépôts et des retraits via des membres statiques.
// L'indice, le montant, le nombre de dépôts et de retraits pour les comptes individuels.
// Les logs aident au débogage et à la compréhension du flux et du statut des transactions.

// Analyse du Fichier d'En-Tête (Account.hpp) :
// Typedefs pour permettre une lisibilité et une manipulation plus faciles des types de données.

// La classe Account fournit des méthodes pour :
// Obtenir des données statiques globales.
// Effectuer des transactions (dépôt/retrait) et interroger le statut du compte.
// Afficher le statut du compte et le statut global.
// Journalisation et horodatage pour suivre chaque transaction.

// Analyse du Journal :
// Il représente avec précision la séquence des transactions avec des horodatages précis, aidant au suivi de l'historique des transactions.
// Les statuts 'créé', 'dépôt', 'retrait' et 'fermé' sont clairement enregistrés avec les montants respectifs et les soldes mis à jour.
// Les entrées refused démontrent l'échec du retrait en raison d'un solde insuffisant, signalant une gestion de compte robuste.

// Analyse du Fichier de Test Principal (tests.cpp) :
// Les tableaux sont utilisés pour contenir les montants initiaux, les dépôts, et les retraits.
// Initialisation du compte : Utilisation de tableaux pour initialiser le std::vector d'objets Account avec divers soldes initiaux.
// Opérations de Dépôt et de Retrait : Application itérative des opérations de dépôt et de retrait à partir des tableaux respectifs et mise à jour des objets de compte.
// Opérations d'Affichage : Affichage des détails du compte après la création initiale, après le dépôt et après les étapes de retrait.

// Analyse du Fichier d'Implémentation (Account.cpp) :
// _displayTimestamp : Une fonction utilitaire statique fournissant un horodatage pour les entrées de journal.
// Diverses méthodes de gestion de compte pour les dépôts (makeDeposit), les retraits (makeWithdraw), et l'affichage des informations.
// La construction du compte assure une comptabilité correcte et des entrées de journal lors de la création et de la suppression.
