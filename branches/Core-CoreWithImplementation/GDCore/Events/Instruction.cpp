/** \file
 *  Game Develop
 *  2008-2013 Florian Rival (Florian.Rival@gmail.com)
 */
#include "GDCore/Events/Instruction.h"
#include "GDCore/Events/Expression.h"
#include <string>
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

namespace gd
{

gd::Expression Instruction::badExpression("");

Instruction::Instruction(string type_) :
renderedHeightNeedUpdate(true),
renderedHeight(0),
selected(false),
type(type_),
inverted(false)
{
    //ctor
    parameters.reserve(8);
}

Instruction::Instruction(string type_, const vector <gd::Expression> & parameters_, bool inverted_) :
renderedHeightNeedUpdate(true),
renderedHeight(0),
selected(false),
type(type_),
inverted(inverted_),
parameters(parameters_)
{
    parameters.reserve(8);
}

const gd::Expression & Instruction::GetParameter(unsigned int index) const
{
    if ( index >= parameters.size() ) return badExpression;

    return parameters[index];
}

gd::Expression & Instruction::GetParameter(unsigned int index)
{
    if ( index >= parameters.size() )  return badExpression;

    return parameters[index];
}

Instruction::~Instruction()
{
    //dtor
}

void Instruction::SetParameter(unsigned int nb, const gd::Expression & val)
{
    if ( nb >= parameters.size() )
    {
        cout << "Tentative d'�criture dans un param�tre invalide.\n\nCeci est peut �tre d� � un bug de Game Develop.\nReportez vous � l'aide pour savoir comment nous rapport une erreur.";
        return;
    }
    parameters[nb] = val;
}


}