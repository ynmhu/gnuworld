/**
 * msg_T.cc
 * Copyright (C) 2002 Daniel Karrels <dan@karrels.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
 * USA.
 *
 * $Id: msg_T.cc,v 1.8 2005/06/20 11:26:33 kewlio Exp $
 */

#include	<string>
#include	<iostream>

#include	"gnuworld_config.h"
#include	"ip.h"
#include	"server.h"
#include	"xparameters.h"
#include	"Network.h"
#include	"ELog.h"
#include	"Channel.h"
#include	"ServerCommandHandler.h"

namespace gnuworld
{

using std::endl ;

CREATE_HANDLER(msg_T)

// Channel topics currently are not tracked.
// kAI T #omniplex :-=[ Washington.DC.US.Krushnet.Org / Luxembourg.
// LU.EU.KrushNet.Org Admin Channel ]=-
bool msg_T::Execute( const xParameters& Param )
{
if( Param.size() < 3 )
	{
	elog	<< "msg_T> Invalid number of arguments"
		<< endl ;
	return false ;
	}

Channel* theChan = Network->findChannel( Param[ 1 ] ) ;
if( 0 == theChan )
	{
	elog	<< "msg_T> Unable to locate channel: "
		<< Param[ 1 ]
		<< endl;
	return false ;
	}

// srcClient may be NULL if a server is setting the topic
iClient* srcClient = Network->findClient( Param[ 0 ] ) ;
std::string newTopic;
bool hasWhoSet = false;

if (Param.size() == 6)
{
	/* this is a >.12.19 hub! */
	/* params = numeric, channel, channel creation ts, topic ts, topic nick, topic */
	newTopic = Param[ 5 ];
#ifdef TOPIC_TRACK
	theChan->setTopic(Param[5]);
	theChan->setTopicTS(atoi(Param[3]));
	theChan->setTopicWhoSet(Param[4]);
	hasWhoSet = true;
#endif // TOPIC_TRACK
} else if (Param.size() == 5)
{
	/* this is a .12 hub! */
	/* params = numeric, channel, channel creation ts, topic ts, topic */
	newTopic = Param[ 4 ];
#ifdef TOPIC_TRACK
	theChan->setTopic(Param[4]);
	theChan->setTopicTS(atoi(Param[3]));
#endif // TOPIC_TRACK
} else {
	/* this is a .11 hub! (3 arguments) */
	/* params = numeric, channel, topic */
	newTopic = Param[ 2 ];
#ifdef TOPIC_TRACK
	theChan->setTopic(Param[2]);
	theChan->setTopicTS(::time(NULL));
#endif // TOPIC_TRACK
}

#ifdef TOPIC_TRACK
/* Even if we have the topic nick (>.12.19) we use srcClient if it was not a burst message */
if (srcClient == NULL && !hasWhoSet)
{
	theChan->setTopicWhoSet("unknown");
} else if (srcClient != NULL) {
	std::string client_ip;
	client_ip = xIP(srcClient->getIP()).GetNumericIP();
	theChan->setTopicWhoSet(srcClient->getNickUserHost() + " [" + client_ip + "]");
}
#endif // TOPIC_TRACK

// No need to pass the new topic, it has already been stored
// in the theChan
// For bursted topics, srcClient will be NULL but getTopicWhoSet() will have been updated (>.12.19).
theServer->PostChannelEvent( EVT_TOPIC,
	theChan,
	static_cast< void* >( srcClient ),
	static_cast< void* >( &newTopic ) ) ;

return true ;
}

} // namespace gnuworld
