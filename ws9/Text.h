#ifndef SENECA_TEXT_H__
#define SENECA_TEXT_H__
#include <ostream>
namespace seneca {
   class Text {
      char* m_filename{};
      char* m_content{};
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);
       // implement rule of three here
       Text(const Text&);
       ~Text();
       Text& operator=(const Text&);

      void read();
      virtual void write(std::ostream& os)const;

   };
    std::ostream& operator<<(std::ostream&,const Text&);
}
#endif // !SENECA_PERSON_H__

