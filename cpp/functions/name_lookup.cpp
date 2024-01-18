// argument_dependent_name_koenig_lookup_on_functions.cpp
namespace Foo
{
   struct Bar
   {
   };
   void func(const Bar&)
   {
   }
}
int main()
{
   Foo::Bar fb;
   func(fb);
   Foo::func(fb);

   return 0;
}