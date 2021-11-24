//============================================================================
// Name        : iZod.cpp
// Project     : iZod
// Author      : Luca Pierobon
//============================================================================

/*
 * iZod.h
 */

#include <string>
#include <vector>
#include <typeinfo>

#include "iZod.h"

double FileAudio::getSize() const {
	return MB;
}
/*virtual*/ bool FileAudio::operator ==(const FileAudio& f) const {
	return typeid(*this)==typeid(f) && titolo==f.titolo && MB==f.MB;
}


Mp3* Mp3::clone() const {
	return new Mp3(*this);
}
bool Mp3::qualita() const {
	return bitrate>=sogliaQualita;
}
unsigned int Mp3::getBitrate() const {
	return bitrate;
}
/*virtual*/ bool Mp3::operator ==(const FileAudio& f) const {
	return FileAudio::operator==(f) && bitrate==static_cast<const Mp3&>(f).bitrate;
}
unsigned int Mp3::sogliaQualita=192;


WAV* WAV::clone() const {
	return new WAV(*this);
}
bool WAV::qualita() const {
	return frequenza>=sogliaQualita;
}
bool WAV::isLossLess() const {
	return lossless;
}
/*virtual*/ bool WAV::operator ==(const FileAudio& f) const {
	return FileAudio::operator==(f) && frequenza==static_cast<const WAV&>(f).frequenza && lossless==static_cast<const WAV&>(f).lossless;
}
unsigned int WAV::sogliaQualita=96;


iZod::Brano::Brano(FileAudio* p): ptr(p->clone()) {}
iZod::Brano::Brano(const Brano& b): ptr(b.ptr->clone()) {}
iZod::Brano& iZod::Brano::operator=(const Brano& b) {
	if(this!=&b) {
		delete ptr; // distruzione polimorfa
		ptr=b.ptr->clone();
	}
	return *this;
}
iZod::Brano::~Brano() {
	delete ptr;
}


std::vector<Mp3> iZod::mp3(double dim, unsigned int br) const {
	std::vector<Mp3> v;
	for(std::vector<Brano>::const_iterator cit=brani.begin(); cit!=brani.end(); ++cit) {
		Mp3* q=dynamic_cast<Mp3*>(cit->ptr);
		if(q && (cit->ptr)->getSize()>dim && q->getBitrate()>br)
			v.push_back(*q);
	}
	return v;
}
std::vector<FileAudio*> iZod::braniQual() const {
	std::vector<FileAudio*> v;
	for(std::vector<Brano>::const_iterator cit=brani.begin(); cit!=brani.end(); ++cit)
		if((cit->ptr)->qualita() && (!dynamic_cast<WAV*>(cit->ptr) || static_cast<WAV*>(cit->ptr)->isLossLess()))
			v.push_back(cit->ptr);
	return v;
}
void iZod::insert(Mp3* m) {
	bool found=false;
	for(auto it=brani.begin(); !found && it!=brani.end(); it++)
		found=*(it->ptr)==*m;
	if(!found)
		brani.push_back(m);
}
