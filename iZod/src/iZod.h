/*
 * iZod.h
 */

#ifndef IZOD_H_
#define IZOD_H_

#include<string>
#include<vector>
#include<typeinfo>

class FileAudio {
private:
	std::string titolo;
	double MB;
public:
	virtual FileAudio* clone() const =0;
	virtual bool qualita() const =0;
	virtual ~FileAudio() {}
	double getSize() const;
	virtual bool operator ==(const FileAudio&) const;
};

class Mp3: public FileAudio {
private:
	static unsigned int sogliaQualita;
	unsigned int bitrate; // Kbit/s
public:
	Mp3* clone() const;
	bool qualita() const;
	unsigned int getBitrate() const;
	virtual bool operator ==(const FileAudio&) const;
};

class WAV: public FileAudio {
private:
	unsigned int frequenza; // in KHz
	bool lossless; // true se e' senza perdita
	static unsigned int sogliaQualita;
public:
	WAV* clone() const;
	bool qualita() const;
	bool isLossLess() const;
	virtual bool operator ==(const FileAudio&) const;
};

class iZod {
private:
	class Brano {
	public:
		FileAudio* ptr;
		// conversione FileAudio* => Brano
		Brano(FileAudio*);
		Brano(const Brano&);
		Brano& operator=(const Brano&);
		~Brano();
	};

	std::vector<Brano> brani;

public:
	std::vector<Mp3> mp3(double, unsigned int) const;
	std::vector<FileAudio*> braniQual() const;
	void insert(Mp3*);
};



#endif /* IZOD_H_ */
