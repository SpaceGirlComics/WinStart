#ifndef OBJECT_H
#define OBJECT_H

/**
* Base Object class
*
* @
* @author Chris Turner
* @version 0.1.4.21.2020
* @see Object.h
*/

#include "String.h"
#include "List.h"
#include "Message.h"

class Object
{
public:
	Object();																					/** Default Constructor */
	Object(const String _id);																	/** Construct with Id */
	Object(const Object& _id);																	/** Copy Constructor */

	Object& operator=(const Object& _rhs);

	void sendMessage(Message* _msg);																/** Send an instruction to this Object */
	void sendMessage(unsigned int _oc, XPARAM _wParam, YPARAM _lParam, const String& Target);	/** Send the parts of a message to this Object */

	virtual List<Message*> update(int _delta);																/** */

	virtual String getType();																	/** returns the type of object*/
	String getId();																				/** Returns the id of this object */
	int getTime();																				/** Returns the time of the last update */

	int setType(String _type);																	/** Set The Type of this object */
	int setId(String _id);																		/** Set The Id of This Object */


	int distinctionCheck(const String& _id);													/** Checks if _id is used as an Id in this objects path */
	int localDistinctionCheck(const String& _id);												/** checks if _id id used as an Id for this object and its sub Objects */

	int addSubObject(Object* _o);

	unsigned int getStatus();

	static const unsigned int LDA = 0x00000000;						// Load Into acc
	static const unsigned int LDL = 0x00000001;						// Load into left
	static const unsigned int LDR = 0x00000002;						// Load into right
	static const unsigned int STA = 0x00000003;						// Store acc
	static const unsigned int STL = 0x00000004;						// Store left
	static const unsigned int STR = 0x00000005;						// Store right
	static const unsigned int TAL = 0x00000006;						// Transfer acc to left
	static const unsigned int TAR = 0x00000007;						// Transfer acc to right
	static const unsigned int TSL = 0x00000008;						// Transfer Local Stack Pointer to left
	static const unsigned int TLA = 0x00000009;						// Transfer left to acc
	static const unsigned int TLS = 0x0000000A;						// Transfer left to Local Stack Pointer
	static const unsigned int TRA = 0x0000000B;						// Transfer right to acc
	static const unsigned int SWP = 0x0000000C;						// Swap Left and Right
	static const unsigned int ADD = 0x0000000D;						// Add Left To Right, Store Result in acc
	static const unsigned int SUB = 0x0000000E;						// Subtract Right From Left, Store Result in acc
	static const unsigned int MUL = 0x0000000F;						// Multiply Left By Right, Store result in acc
	static const unsigned int DIV = 0x00000010;						// Divide left by right, Store Result in acc
	static const unsigned int DCI = 0x00000011;						// Declare Integer, Stored In SubObject List
	static const unsigned int DCF = 0x00000012;						// Declare Float, Stored In SubObject List
	static const unsigned int DCS = 0x00000013;						// Declare String, Stored In SubObject List
	static const unsigned int DCO = 0x00000014;						// Declare Object, Stored In SubObject List
	static const unsigned int JPL = 0x00000015;						// Jump if acc is less than LPARAM
	static const unsigned int JPG = 0x00000016;						// Jump if acc is greater than LPARAM
	static const unsigned int JEQ = 0x00000017;						// Jump if acc is Equal to LPARAM
	static const unsigned int JEZ = 0x00000018;						// Jump if acc is Zero
	static const unsigned int JNZ = 0x00000019;						// Jump if acc is Not Zero
	static const unsigned int KIL = 0x0000001A;						// Delete Subobject
	static const unsigned int NMP = 0x00002000;						// Create New Map
	~Object();

protected:
	String id;														/** Unique Identifier for this Object */
	String type;													/** Identifies the Data/Object type of this object*/

	int time;														/** time, in milliseconds, since instanciation */
	int delta;														/** time, in milliseconds, since this objects update function was called */
	int expiry;														/** time, in milliseconds, this ojbect will exist for, if negative the object will live forever */
	int left, right, acc;											/** General purpose "Registers" */
	int sp;															/** Local Stack Pointer */
	unsigned int status;											/** Status Register */
	static int count;												/** total number of current intances */

	List<Message*> inbox;											/** List of meesages for this object and its sub Objects */
	List<Message*> outbox;											/** List for ascending messages */
	List<Object*> subs;												/** List of Sub Objects; Rem. to make an RBT or AVL class for this instead */

	void pump();													/** Removes Messages from Queue and Sends them to pro() or the targeted subject */
	virtual void proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam);	/** Processes messages this object receives */
	//String temp;
};
#endif
